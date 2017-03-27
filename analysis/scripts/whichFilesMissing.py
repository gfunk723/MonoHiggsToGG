import sys

def AllGlobal(fname):
  fin  = open(fname,"r")
  fout = open(fname+"_log","w")

  lines = []
  for line in fin:
    lines.append(int(line))

  lines.sort()
  size = len(lines)
  n    = size-1
  
  for i in range(0,n):
    diff = lines[i+1] - lines[i] - 1 
    if diff==0:
       continue
    else:
       for x in range(0,diff):
         missing = lines[i]+x+1
         fout.write(str(missing)+"\n")

if __name__ == "__main__":
  AllGlobal("test")   
