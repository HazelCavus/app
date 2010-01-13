/***************************************************************************
 SocNetV: Social Networks Visualizer
 version: 0.90
 Written in Qt 4.4
 
                         datasetrecreatordialog.h  -  description
                             -------------------
    copyright            : (C) 2005-2010 by Dimitris B. Kalamaras
    email                : dimitris.kalamaras@gmail.com
 ***************************************************************************/

/*******************************************************************************
*     This program is free software: you can redistribute it and/or modify     *
*     it under the terms of the GNU General Public License as published by     *
*     the Free Software Foundation, either version 3 of the License, or        *
*     (at your option) any later version.                                      *
*                                                                              *
*     This program is distributed in the hope that it will be useful,          *
*     but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
*     GNU General Public License for more details.                             *
*                                                                              *
*     You should have received a copy of the GNU General Public License        *
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
********************************************************************************/

#ifndef DATASETRECREATORDIALOG_H
#define DATASETRECREATORDIALOG_H

#include <QDialog>

#include "ui_datasetrecreatordialog.h"
 

class DataSetRecreatorDialog: public QDialog
{
	Q_OBJECT
public:
	DataSetRecreatorDialog (QWidget *parent = 0);
public slots:
	void gatherData();
signals:
	void userChoices(QString);	
private:
	Ui::DataSetRecreatorDialog ui;

};



#endif
