#!/usr/bin/python

import os, sys, subprocess, select


if len(sys.argv) < 2:
    print 'usage: run.py num'
    sys.exit(1)
    

cwd = os.getcwd().split('/')[-1]
year = int( cwd[:4] )
if year < 2010 or year > 2030:
    print 'E: wrong year %d' % year
    sys.exit(1)

qid = 'a'
tid = ''
if year < 2018:
    qid = sys.argv[1][0].lower()
    if len(sys.argv[1]) > 1: tid = sys.argv[1][1].lower()
else:
    qid = sys.argv[1]
    
if 'abcdef'.find(qid) < 0:
    print 'E: qid should be abcdef'
    sys.exit(1)
    
fcpp = '%s.cpp' % qid
fpy = '%s.py' % qid
ftxt = '%s%s.txt' % (qid, tid)
fbin = '%s.bin' % qid
fttpy = '%s-tt.py' % qid

if not os.path.exists(fpy):
    changed = True
    clines = '''
int solve(){
    return 0;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << solve() << endl;
    }
    return 0;
}
    '''
    if os.path.exists(fcpp):
        with open(fcpp, 'r') as f:
            clines = f.read()
            changed = False

    if 'bits/stdc++.h' not in clines:
        clines = '''
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SIZE(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// ------------------------
    ''' + clines
        changed = True


    if changed:
        with open(fcpp, 'w') as f:
            f.write(clines)
            
    opts = '-O2'
    if '-g' in sys.argv: opts = '-g'
    if os.system('g++ %s -o %s %s' % (opts, fbin, fcpp)) != 0:
        sys.exit(1)
        
else:
    fbin = fpy
        

fdownload = '%s/Downloads/%s-%s-practice.in' % (os.environ['HOME'], qid.upper(), 'small' if tid == 's' else 'large')
if os.path.exists(fdownload):
    os.rename(fdownload, ftxt)

if os.path.exists(ftxt):
    cmd = './%s <%s' % (fbin, ftxt)
    if tid != '': cmd += ' >%s' % ftxt.replace('.txt', '.out')
    os.system(cmd)
    sys.exit(0)

fdownload = '%s/Downloads/testing_tool.py' % os.environ['HOME']
if os.path.exists(fdownload):
    os.rename(fdownload, fttpy)
    
if os.path.exists(fttpy):
    print '!RUN interactive test'
    
    with open(fttpy, 'r') as f:
        lines = f.read()

    args = ['./' + fbin]
    if fbin.endswith('.py'): args = ['/usr/bin/python', fbin]
    
    if 'subprocess.Popen' in lines:
        os.system('python %s %s' % (fttpy, ' '.join(args)))
        sys.exit(0)
    
    ptt = subprocess.Popen(['/usr/bin/python', fttpy, "0"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    pbin = subprocess.Popen(args, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    
    ploop = select.poll()
    ploop.register(pbin.stdout.fileno(), select.POLLIN)
    ploop.register(ptt.stdout.fileno(), select.POLLIN)
    while True:
        if pbin.poll() or ptt.poll(): break
        for fd,evt in ploop.poll():
            #print '!', fd, evt
            if fd == pbin.stdout.fileno():
                b = pbin.stdout.readline()
                if len(b) == 0: break
                #print ">", b
                ptt.stdin.write(b)
            if fd == ptt.stdout.fileno():
                b = ptt.stdout.readline()
                if len(b) == 0: break
                #print "<", b
                pbin.stdin.write(b)
    sys.exit(0)

print >>sys.stderr, 'no %s or %s found' % (ftxt, fttpy)
sys.exit(1)

