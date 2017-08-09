from optparse import OptionParser, OptionGroup, make_option
import sys
import os

# -------------------------------------------------------------
class pyapp(object):

  def __init__(self,option_list,option_groups=[],defaults=None):
    self.objs_  = []
    self.canvs_ = []
    self.files_ = {} 
 
    opt_list = [
      make_option("-I","--interactive",action="store_true",dest="interactive",
                  default=sys.flags.interactive,help="default: %default",metavar=""),
      make_option("-O","--outdir",action="store",dest="outdir",type="string",
                  default=None,help="default: %default")
      ] # end opt_list
 
    parser = OptionParser()

    opt_groups = [ ("PyApp Options", opt_list ) ] + option_groups
    if len(option_list) > 0:
      opt_groups.append( ("User Options", option_list) )

    for name,opts in opt_groups:
      gr = OptionGroup(parser,name)
      for opt in opts:
        gr.add_option(opt)
      parser.add_option_group(gr)

    (self.options, self.args) = parser.parse_args()

    # make output directory
    if self.options.outdir:
      if os.path.isdir(self.options.outdir):
        print("Will write to Output Directory: %s" %self.options.outdir)
      else: 
        print("Making Output Directory: %s" %self.options.outdir)
        os.mkdir(self.options.outdir)

    global ROOT
    import ROOT


  def run(self):
    self.__call__(self.options,self.args)
 
