/***************************************************************************
 SocNetV: Social Networks Visualiser
 version: 0.46
 Written in Qt 4.4 with KDevelop 
 
                         graphicswidget.h  -  description
                             -------------------
    copyright            : (C) 2005-2008 by Dimitris B. Kalamaras
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

#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H


#include <QtGui/QGraphicsView>
#include "graph.h"
#include <QGraphicsScene>

class MainWindow;
//class QGraphicsSceneMouseEvent;
class Node;
class Edge;
class NodeNumber;
class NodeLabel;
class BackgrCircle;

class GraphicsWidget : public QGraphicsView {
	Q_OBJECT
public:
 	GraphicsWidget(QGraphicsScene*, MainWindow* parent);
	~GraphicsWidget();
	void clear();
	void addNode(int i, int value, int size, QString aColor, QString label, QString lColor, QPointF p, QString nodeShape, bool showLabels, bool showNnumbers) ;
	void removeNode(int doomedJim);
	void addEdge(Node*,Node*, bool, QString, bool);
	void addEdge(int, int, bool, bool, QString, bool);
	void removeEdge(int, int);
	void removeItem(Edge*);
	void removeItem(Node*);
	void removeItem(NodeNumber*);
	void removeItem(NodeLabel*);
	void itemMoved();
	void nodeMoved(int, int,int);
	void updateNode(int, int, int);
	void setInitNodeColor(QString);
	void setInitLinkColor(QString);
	void setInitNodeSize(int);
	void setInitNumberDistance(int);
	void setInitLabelDistance(int);
	bool setNodeColor(int, QString);
	bool setEdgeColor(int, int, QString);
	void setAllItemsVisibility(int, bool);

protected:
	void timerEvent(QTimerEvent *event);
	void wheelEvent(QWheelEvent *event);
	void mouseDoubleClickEvent ( QMouseEvent * e );
	void resizeEvent( QResizeEvent *e );

public slots:
	void nodeClicked(Node *);
	void edgeClicked(Edge *);
	void openNodeContextMenu();
	void openEdgeContextMenu();
	void startNodeMovement(int state);
	void changeScale(int sliderValue); 
	void edgeNodes(Node *node);	
	void clearBackgrCircles();
	void addBackgrCircle( int x0, int y0, int radius);
	void addBackgrHLine(int y0);
	void zoomIn();
	void zoomOut();
	void rot(int angle);

signals:
	void windowResized(int,int);
	void userDoubleClicked(int, int, int);
	void userMiddleClicked(int, int, int);
	void openNodeMenu();
	void openEdgeMenu();
	void updateNodeCoords(int, int, int);
	void selectedNode(Node *);
	void selectedEdge(Edge *);
 	void changed();
	void scaleChanged(int);
	
private:
	int timerId,  m_nodeSize, m_numberDistance, m_labelDistance;
	qreal m_scale;
	QTransform init_Transform;
	qreal scaleFactor, oldFactor;
	QString m_nodeLabel, m_numberColor, m_nodeColor, m_labelColor, m_linkColor;
	bool secondDoubleClick, dynamicMovement;
	QGraphicsItem *moving;
	QPointF moving_start;
	Node *firstNode, *secondNode ;
	vector<Node*> nodeVector;
};

#endif