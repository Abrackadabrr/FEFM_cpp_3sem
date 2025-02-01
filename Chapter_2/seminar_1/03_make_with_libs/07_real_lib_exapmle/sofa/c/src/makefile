#-----------------------------------------------------------------------
#
# Description:  make file for the ANSI-C version of SOFA.  This
# make file creates a Unix .a library.  Designed for Linux/gcc but
# can be adapted for other platforms or run in an appropriate way
# by means of the macros CCOMPC (compiler command), CFLAGF (qualifiers
# for compiling functions) and CFLAGX (qualifiers for compiling
# executables).
#
# Usage:
#
#    To build the library:
#
#      make
#
#    To install the library and include files:
#
#      make install
#
#    To delete all object files:
#
#      make clean
#
#    To build and run the test program using the installed library:
#
#      make test
#
#    Also:
#      make all           same as make
#      make uninstall     deinstall the library and header files
#      make check         test the build
#      make installcheck  same as make test
#      make distclean     delete all generated binaries
#      make realclean     same as distclean
#
# Last revision:   2021 April 18
#
# Copyright International Astronomical Union.  All rights reserved.
#
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
#
#  DEFINITIONS
#
#-----------------------------------------------------------------------

#----YOU MAY HAVE TO MODIFY THE NEXT FEW DEFINITIONS-----

# Specify the installation home directory.


INSTALL_DIR = $(HOME)

# Specify the installation directory for the library.

SOFA_LIB_DIR = $(INSTALL_DIR)/lib/

# Specify the installation directory for the include files.

SOFA_INC_DIR = $(INSTALL_DIR)/include/

# This software is compilable only by ANSI C compilers - give the name
# of your preferred C compiler (CCOMPC) and compilation flags (CFLAGF
# for functions, CFLAGX for executables) here.

CCOMPC = gcc
CFLAGF = -c -pedantic -Wall -O
CFLAGX = -pedantic -Wall -O

#----YOU SHOULDN'T HAVE TO MODIFY ANYTHING BELOW THIS LINE---------

SHELL = /bin/sh

# The list of installation directories.

INSTALL_DIRS = $(SOFA_LIB_DIR) $(SOFA_INC_DIR)

# Name the SOFA/C library in its source and target locations.

SOFA_LIB_NAME = libsofa_c.a
SOFA_LIB = $(SOFA_LIB_DIR)$(SOFA_LIB_NAME)

# Name the SOFA/C testbed in its source and target locations.

SOFA_TEST_NAME = t_sofa_c.c
SOFA_TEST = t_sofa_c

# Name the SOFA/C includes in their source and target locations.

SOFA_INC_NAMES = sofa.h sofam.h
SOFA_INC = $(SOFA_INC_DIR)sofa.h $(SOFA_INC_DIR)sofam.h

# The list of SOFA/C library object files.

SOFA_NAMES = a2af.  a2tf.  ab.  ae2hd.  af2a.  anp.  anpm.  apcg.  apcg13.  apci.  apci13.  apco.  apco13.  apcs.  apcs13.  aper.  aper13.  apio.  apio13.  atcc13.  atccq.  atci13.  atciq.  atciqn.  atciqz.  atco13.  atic13.  aticq.  aticqn.  atio13.  atioq.  atoc13.  atoi13.  atoiq.  bi00.  bp00.  bp06.  bpn2xy.  c2i00a.  c2i00b.  c2i06a.  c2ibpn.  c2ixy.  c2ixys.  c2s.  c2t00a.  c2t00b.  c2t06a.  c2tcio.  c2teqx.  c2tpe.  c2txy.  cal2jd.  cp.  cpv.  cr.  d2dtf.  d2tf.  dat.  dtdb.  dtf2d.  eceq06.  ecm06.  ee00.  ee00a.  ee00b.  ee06a.  eect00.  eform.  eo06a.  eors.  epb.  epb2jd.  epj.  epj2jd.  epv00.  eqec06.  eqeq94.  era00.  fad03.  fae03.  faf03.  faju03.  fal03.  falp03.  fama03.  fame03.  fane03.  faom03.  fapa03.  fasa03.  faur03.  fave03.  fk425.  fk45z.  fk524.  fk52h.  fk54z.  fk5hip.  fk5hz.  fw2m.  fw2xy.  g2icrs.  gc2gd.  gc2gde.  gd2gc.  gd2gce.  gmst00.  gmst06.  gmst82.  gst00a.  gst00b.  gst06.  gst06a.  gst94.  h2fk5.  hd2ae.  hd2pa.  hfk5z.  icrs2g.  ir.  jd2cal.  jdcalf.  ld.  ldn.  ldsun.  lteceq.  ltecm.  lteqec.  ltp.  ltpb.  ltpecl.  ltpequ.  moon98.  num00a.  num00b.  num06a.  numat.  nut00a.  nut00b.  nut06a.  nut80.  nutm80.  obl06.  obl80.  p06e.  p2pv.  p2s.  pap.  pas.  pb06.  pdp.  pfw06.  plan94.  pm.  pmat00.  pmat06.  pmat76.  pmp.  pmpx.  pmsafe.  pn.  pn00.  pn00a.  pn00b.  pn06.  pn06a.  pnm00a.  pnm00b.  pnm06a.  pnm80.  pom00.  ppp.  ppsp.  pr00.  prec76.  pv2p.  pv2s.  pvdpv.  pvm.  pvmpv.  pvppv.  pvstar.  pvtob.  pvu.  pvup.  pvxpv.  pxp.  refco.  rm2v.  rv2m.  rx.  rxp.  rxpv.  rxr.  ry.  rz.  s00.  s00a.  s00b.  s06.  s06a.  s2c.  s2p.  s2pv.  s2xpv.  sepp.  seps.  sp00.  starpm.  starpv.  sxp.  sxpv.  taitt.  taiut1.  taiutc.  tcbtdb.  tcgtt.  tdbtcb.  tdbtt.  tf2a.  tf2d.  tpors.  tporv.  tpsts.  tpstv.  tpxes.  tpxev.  tr.  trxp.  trxpv.  tttai.  tttcg.  tttdb.  ttut1.  ut1tai.  ut1tt.  ut1utc.  utctai.  utcut1.  xy06.  xys00a.  xys00b.  xys06a.  zp.  zpv.  zr. 

SOFA_OBS = $(SOFA_NAMES:.=.o)

#-----------------------------------------------------------------------
#
#  TARGETS
#
#-----------------------------------------------------------------------
.PHONY: all install uninstall check clean
# Build (but do not install) the library.
all : $(SOFA_LIB_NAME)
	-@ echo ""
	-@ echo "*** Now type 'make test'" \
                " to install the library and run tests ***"
	-@ echo ""

# Install the library and header files.
install $(SOFA_LIB) : $(INSTALL_DIRS) $(SOFA_LIB_NAME) $(SOFA_INC)
	cp $(SOFA_LIB_NAME) $(SOFA_LIB_DIR)

# Deinstall the library and header files.
uninstall:
	- $(RM) $(SOFA_LIB) $(SOFA_INC)

# Test the build.
check: $(SOFA_TEST_NAME) $(SOFA_INC_NAMES) $(SOFA_LIB_NAME)
	$(CCOMPC) $(CFLAGX) $(SOFA_TEST_NAME) $(SOFA_LIB_NAME) \
        -I. -lm -o $(SOFA_TEST)
	./$(SOFA_TEST)

# Test the installed library.
installcheck test: $(SOFA_TEST_NAME) $(SOFA_INC) $(SOFA_LIB)
	$(CCOMPC) $(CFLAGX) $(SOFA_TEST_NAME) -I$(SOFA_INC_DIR) \
        -L$(SOFA_LIB_DIR) -lsofa_c -lm -o $(SOFA_TEST)
	./$(SOFA_TEST)

# Delete object files.
clean :
	- $(RM) $(SOFA_OBS)

# Delete all generated binaries in the current directory.
realclean distclean : clean
	- $(RM) $(SOFA_LIB_NAME) $(SOFA_TEST)

# Create the installation directories if not already present.
$(INSTALL_DIRS):
	mkdir -p $@

# Build the library.
$(SOFA_LIB_NAME): $(SOFA_OBS)
	ar ru $(SOFA_LIB_NAME) $?

# Install the header files.
$(SOFA_INC) : $(INSTALL_DIRS) $(SOFA_INC_NAMES)
	cp $(SOFA_INC_NAMES) $(SOFA_INC_DIR)

#-----------------------------------------------------------------------

# The list of object file dependencies

%.o: %.c   sofa.h sofam.h
	$(CCOMPC) $(CFLAGF) -o $@ $<

#------------------------------------------------------------------------
