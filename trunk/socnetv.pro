lessThan(QT_VERSION, 4.8) {
    error("SocNetV requires at least Qt 4.8!")
}

# START added for ArchLinux / openSUSE compatibility
INSTALLPATH = /
target.path = $$[INSTALLPATH]usr/bin
TARGET = socnetv

pixmap.path = $$[INSTALLPATH]usr/share/pixmaps
pixmap.files = src/images/socnetv.png

documentation.path = $$[INSTALLPATH]usr/share/doc/socnetv
documentation.files = manual

manpage.path = $$[INSTALLPATH]usr/share/man/man1
manpage.files = man/socnetv.1.gz

translations.path = $$[INSTALLPATH]usr/share/socnetv
translations.files = translations

doc.path = $$[INSTALLPATH]usr/share/doc/socnetv
doc.files = license ChangeLog NEWS README TODO COPYING AUTHORS INSTALL

INSTALLS += target pixmap documentation manpage translations doc

# END


TEMPLATE = app
CONFIG  += qt thread warn_on release
LANGUAGE = C++

# support
QT += webkitwidgets
QT += xml 
QT += network
QT += widgets
QT += printsupport 

INCLUDEPATH  += ./src
FORMS += src/forms/filteredgesbyweightdialog.ui \
	src/forms/webcrawlerdialog.ui \
	src/forms/datasetselectdialog.ui 

HEADERS += src/guide.h \
           src/graphicswidget.h \
           src/edge.h \
           src/edgeweight.h \
           src/graph.h \
           src/htmlviewer.h \
           src/mainwindow.h \
           src/matrix.h \
           src/node.h \
           src/nodelabel.h \
           src/nodenumber.h \
           src/texteditor.h \
           src/vertex.h \ 
  	   src/parser.h \
	   src/filteredgesbyweightdialog.h \
	   src/webcrawlerdialog.h \
	   src/webcrawler.h \
	   src/datasetselectdialog.h

SOURCES += src/guide.cpp \
           src/graphicswidget.cpp \
           src/edge.cpp \
           src/edgeweight.cpp \
           src/graph.cpp \
           src/htmlviewer.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/matrix.cpp \
           src/node.cpp \
           src/nodelabel.cpp \
           src/nodenumber.cpp \
           src/texteditor.cpp \
           src/vertex.cpp \
           src/parser.cpp \
	   src/filteredgesbyweightdialog.cpp \
	   src/webcrawlerdialog.cpp \
	   src/webcrawler.cpp \
	   src/datasetselectdialog.cpp



# Extra optimization flags
QMAKE_CXXFLAGS += -msse -mfpmath=sse -ffast-math 

#LIBS    += @ac_libs@
INCLUDEPATH +=  /usr/local/include /usr/include /usr/include/qt5 /usr/share/qt5/include 
INCLUDEPATH +=  /usr/local/include /usr/include /usr/include/qt  /usr/include/qt5 /usr/share/qt5/include

RESOURCES = src/src.qrc
win32 {
     RC_FILE = src/icon.rc
}

macx:ICON = src/images/socnetv.icns


TRANSLATIONS    = translations/socnetv_es.ts 




