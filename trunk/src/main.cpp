/***************************************************************************
 SocNetV: Social Networks Visualiser 
 version: 0.46
 Written in Qt 4.4 with KDevelop   

                        main.cpp  -  description
                             -------------------
    begin                :  9 21:10:04 EET 2005
    copyright            : (C) 2005, 2006, 2007 by Dimitris B. Kalamaras
    email                : dimitris.kalamaras@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <QApplication>		//core Qt functionality
#include <QTranslator>		//for text translations
#include <QLocale>
#include <iostream>		//used for cout
#include "mainwindow.h"		//main application window

using namespace std;

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(src);
	QApplication app(argc, argv);
	
	QTranslator tor( 0 );
	QLocale locale;
	// set the location where your .qm files are in load() below as the last parameter instead of "."
	// for development, use "/" to use the english original as
	// .qm files are stored in the base project directory.
	tor.load( QString("socnetv.") + locale.name(), "." );
	app.installTranslator( &tor );
  
	//Check if a filename is passed when this program is called.
	QString option;
	if ( app.argc() > 1 )     {
		option = app.argv()[1];
		if ( option.endsWith( ".net" ) ||  option.endsWith( ".csv" ) || option.endsWith( ".txt" ) || option.endsWith( ".graphml" ) || option.endsWith( ".gml" ) || option.endsWith( ".dot" ) ) {
			if (option=="--help" || option=="-h" ) {

				cout<<"\n Usage:\n socnetv [flags] [file]\n";
				cout<<"-h, --help 	Displayes this help message\n";
				cout<<"-V, --version	Displays version number\n\n";
				
				cout<<"You can load a network from a file using \n";
				cout<<"socnetv file.net \n";
				cout<<"where file.net/csv/dot/graphml must be of valid format. See README\n\n";

				cout<<"Please send any bug reports to dimitris.kalamaras@gmail.com.";
				return -1;
			}
			else if (option=="-V" || option=="--version") {
				cout<< "\n\nSocial Networks Visualiser \n\nVersion 0.46\n";
				return -1;
			}
			else {
				option = QString::null;
			}
		}
	}
	MainWindow *socnetv=new MainWindow(option);
	socnetv->show();
	return app.exec();
}

