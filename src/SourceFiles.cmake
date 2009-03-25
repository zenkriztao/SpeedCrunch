# speedcrunch

set(speedcrunch_HEADERS
#variant/variantbase.hxx
#variant/variant.hxx
#variant/real.hxx
3rdparty/flickcharm/flickcharm.h
#3rdparty/binreloc/binreloc.h
core/constants.hxx
core/evaluator.hxx
core/functions.hxx
#core/settings.hxx
gui/aboutbox.hxx
gui/application.hxx
gui/autohidelabel.hxx
gui/bookdock.hxx
gui/constantsdock.hxx
gui/constantswidget.hxx
gui/deletevardlg.hxx
gui/resultdisplay.hxx
gui/editor.hxx
gui/functionsdock.hxx
gui/functionswidget.hxx
gui/historydock.hxx
gui/historywidget.hxx
gui/insertfunctiondlg.hxx
gui/insertvardlg.hxx
gui/keypad.hxx
gui/tipwidget.hxx
gui/variablesdock.hxx
gui/variableswidget.hxx
gui/mainwindow.hxx
#math/floatcommon.h
#math/floatconfig.h
#math/floatconst.h
#math/floatconvert.h
#math/floaterf.h
#math/floatexp.h
#math/floatgamma.h
#math/floathmath.h
#math/floatio.h
#math/floatipower.h
#math/floatlog.h
#math/floatlogic.h
#math/floatlong.h
#math/floatnum.h
#math/floatpower.h
#math/floatseries.h
#math/floattrig.h
#math/hmath.hxx
#math/number.h
)

set(speedcrunch_SOURCES
#variant/variantbase.cpp
#variant/variant.cpp
#variant/real.cpp
#variant/vstring.cpp
#variant/initvariant.cpp
#variant/formatbase.cpp
#variant/formatreal.cpp
3rdparty/binreloc/binreloc.c
3rdparty/flickcharm/flickcharm.cpp
core/constants.cpp
core/evaluator.cpp
core/functions.cpp
core/settings.cpp
gui/aboutbox.cpp
gui/application.cpp
gui/autohidelabel.cpp
gui/bookdock.cpp
gui/constantsdock.cpp
gui/constantswidget.cpp
gui/deletevardlg.cpp
gui/resultdisplay.cpp
gui/editor.cpp
gui/functionsdock.cpp
gui/functionswidget.cpp
gui/historydock.cpp
gui/historywidget.cpp
gui/insertfunctiondlg.cpp
gui/insertvardlg.cpp
gui/keypad.cpp
gui/tipwidget.cpp
gui/variablesdock.cpp
gui/variableswidget.cpp
gui/mainwindow.cpp
main/main.cpp
math/floatcommon.c
math/floatconst.c
math/floatconvert.c
math/floaterf.c
math/floatexp.c
math/floatgamma.c
math/floathmath.c
#math/floatincgamma.c
math/floatio.c
math/floatipower.c
math/floatlog.c
math/floatlogic.c
math/floatlong.c
math/floatnum.c
math/floatpower.c
math/floatseries.c
math/floattrig.c
math/hmath.cpp
math/number.c
)

# regression test for HMath
set(testhmath_SOURCES
math/floatcommon.c
math/floatconst.c
math/floatconvert.c
math/floaterf.c
math/floatexp.c
math/floathmath.c
math/floatgamma.c
#math/floatincgamma.c
math/floatio.c
math/floatipower.c
math/floatlog.c
math/floatlogic.c
math/floatlong.c
math/floatnum.c
math/floatpower.c
math/floatseries.c
math/floattrig.c
math/hmath.cpp
math/number.c
test/testhmath.cpp
)

# regression test for Evaluator
set(testevaluator_HEADERS
core/evaluator.hxx
core/functions.hxx
)

set(testevaluator_SOURCES
core/evaluator.cpp
core/functions.cpp
core/settings.cpp
math/floatcommon.c
math/floatconst.c
math/floatconvert.c
math/floaterf.c
math/floatexp.c
math/floathmath.c
math/floatgamma.c
#math/floatincgamma.c
math/floatio.c
math/floatipower.c
math/floatlog.c
math/floatlogic.c
math/floatlong.c
math/floatnum.c
math/floatpower.c
math/floatseries.c
math/floattrig.c
math/hmath.cpp
math/number.c
test/testevaluator.cpp
)

# regression test for floatnum
set(testfloatnum_SOURCES
math/floatcommon.c
math/floatconst.c
math/floatconvert.c
math/floaterf.c
math/floatexp.c
math/floathmath.c
math/floatgamma.c
math/floatio.c
math/floatipower.c
math/floatlog.c
math/floatlogic.c
math/floatlong.c
math/floatnum.c
math/floatpower.c
math/floatseries.c
math/floattrig.c
math/number.c
test/testfloatnum.c
)

