#!/usr/bin/python

import os, sys, subprocess, select


if len(sys.argv) < 2:
    print 'usage: run.py num [options]'
    sys.exit(1)
    
tid = ''
qid = sys.argv[1]
if '.' in qid: 
    qid = qid.split('.')[0]

cwd = os.getcwd().split('/')[-1]
if cwd in ('hdu', 'poj', 'zoj'):
    if int(qid) < 10:
        print 'E: wrong problem %s' % qid
else:
    year = int( cwd[:4] )
    if year < 2010 or year > 2030:
        print 'E: wrong year %d' % year
        sys.exit(1)

    if year < 2018:
        if len(qid) > 1: tid = qid[1].lower()
        qid = qid[0].lower()
    
    if 'abcdef'.find(qid) < 0:
        print 'E: qid should be abcdef'
        sys.exit(1)
    
fcpp = '%s.cpp' % qid
fpy = '%s.py' % qid
ftxt = '%s%s.txt' % (qid, tid)
fbin = '%s.bin' % qid
fttpy = '%s-tt.py' % qid

if not os.path.exists(fpy):
    def readcpp(fname):
        ret = []
        with open(fname, 'r') as f:
            name = 'main'
            txt = ''
            for line in f:
                if line.startswith('//+'):
                    if len(txt) > 0: ret.append( (name, txt.strip()) )
                    name = line[3:].strip()
                    txt = ''
                else:
                    txt += line
            if len(txt) > 0: ret.append( (name, txt.strip()) )
        return ret
    
    template = readcpp('../template.cpp')

    origin = {}
    if os.path.exists(fcpp):
        for n,v in readcpp(fcpp):
            origin[n] = v

    txt = ''
    changed = False
    for n,v in template:
        if n in origin:
            txt += '//+%s\n%s\n\n' % (n, origin[n])
            continue
        if n in ('base', 'main') or ('+'+n) in sys.argv:
            txt += '//+%s\n%s\n\n' % (n, v)
            changed = True

    if changed:
        with open(fcpp, 'w') as f:
            f.write(txt)
            
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

