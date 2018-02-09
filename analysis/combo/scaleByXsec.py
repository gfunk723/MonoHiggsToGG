import sys, os, re

xsecfile = open('crosssectionZp2HDM.txt','r')
#xsecfile = open('crosssectionZpBaryonic.txt','r')
limitpts = os.listdir('.')
outdir   = 'weighted_limits'
if not [os.path.isdir(outdir)]: os.mkdir(outdir)

# pick up limit files
regex = re.compile('Zprime.*json')
lfile = filter(regex.match,limitpts)
#print lfile

m_Z  = []
m_A  = []
xsec = []
mass = []
xsecs = {}

# read in xsecs
for line in xsecfile:
  line = line.rstrip('\n')
  line = line.split(' ')
  m_Z.append(line[0])
  m_A.append(line[1])
  xsec.append(line[2]) 
  massstr = line[0]+'_'+line[1]
  mass.append(massstr)
  xsecs[massstr] = line[2] 

# loop over jsons
for l in lfile: 
  name = l.replace('Zprime','')
  name = name.replace('.json','')
  name = name.split('A')
  zp   = name[0]
  a0   = name[1]
  findmass = zp+'_'+a0
  xsecwgt  = xsecs[findmass] 

  # open new file
  json_orig = open(l,'r')
  json_new  = open(outdir+'/'+l,'w')

  # loop over 
  for limitline in json_orig:
    limitline = limitline.rstrip('\n')
    limitline = limitline.rstrip(',')
    if ':' in limitline and '{' not in limitline:
      values = limitline.split(':')
      value  = values[1]
      numval = float(value)
      wgtval = numval/float(xsecwgt)
      #print wgtval
      if 'obs' in limitline:  json_new.write(values[0]+': '+str(wgtval)+'\n')
      else:                   json_new.write(values[0]+': '+str(wgtval)+',\n')
    else:
      json_new.write(limitline+'\n') 

