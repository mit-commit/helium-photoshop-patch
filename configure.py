filters = ["blur", "sharpen", "sharpenmore", "invert", "threshold", "despeckle", "noise", "sharpenedges", "equalize", "brightness", "boxblur"]

halide_out_h = ' '.join(["halide_out_{}.h".format(f) for f in filters])
halide_out_o = ' '.join(["halide_out_{}.o".format(f) for f in filters])

print "#Add /DHELIUM_PARALLEL to get parallel schedules"
print "CFLAGS=/nologo /O2 /Oy- /Zi"
print "LDFLAGS=/nologo /dll /force:multiple /ignore:4006 /debug"
print

print "combineddll.dll: combineddll.cpp", halide_out_o, halide_out_h
print "    $(CC) $(CFLAGS) /I. /c combineddll.cpp"
print "    link.exe $(LDFLAGS) combineddll.obj", halide_out_o
print
for f in filters:
  print "halide_out_{0}.o halide_out_{0}.h: photoshop_{0}.cpp".format(f)
  print "    $(CC) $(CFLAGS) /I. Halide.lib photoshop_{}.cpp".format(f)
  print "    photoshop_{}.exe".format(f)
print

print "clean:"
print "    del combineddll.dll combineddll.obj combineddll.pdb"
print "    del halide_out_* photoshop*.exe photoshop_*.obj photoshop_*.ilk photoshop_*.pdb"
print "    del vc120.pdb"