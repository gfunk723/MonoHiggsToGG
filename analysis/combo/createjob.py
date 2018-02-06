import sys, os

def run(mass):

  infile  = open('submitjob.tmpl','r')
  outfile = open('submitjob'+mass+'.tmpl','w')
  for line in infile:
    lineout = line.replace('MASS',mass)
    outfile.write(lineout)

if __name__=="__main__":

  mass=sys.argv[1]
  run(mass)
