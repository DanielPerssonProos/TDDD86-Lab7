#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include "Point.h"
#include "map"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>


static const int SCENE_WIDTH = 512;
static const int SCENE_HEIGHT = 512;

using namespace std;

void render_points(QGraphicsScene* scene, const vector<Point*>& points) {
    for(const auto& point : points) {
        point->draw(scene);
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsView *view = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene(0, 0, SCENE_WIDTH, SCENE_HEIGHT);



    string filename = "input150.txt";
    ifstream input;
    input.open(filename);

    // the vector of points
    vector<Point*> points;

    // read points from file
    int N;
    int x;
    int y;

    input >> N;
    for (int i = 0; i < N; ++i) {
        input >> x >> y;
        points.push_back(new Point(x, y));
    }
    input.close();

    view->setScene(scene);
    render_points(scene, points);
    view->scale(1, -1); //screen y-axis is inverted
    view->resize(view->sizeHint());
    view->setWindowTitle("Fast Pattern Recognition");
    view->show();

    auto begin = chrono::high_resolution_clock::now();


    for(int i = 0; i < points.size(); ++i){
        map<double,vector<Point*>> pointsMap;
        for(int k = i + 1; k < points.size(); ++k){
            double slope = points[i]->slopeTo(*points[k]);
            pointsMap[slope].push_back(points[k]);
        }

        for(map<double,vector<Point*>>::iterator j = pointsMap.begin(); j != pointsMap.end(); ++j){
            if(j->second.size() >= 3){

                for(auto l = j->second.begin(); l != j->second.end(); ++l) {
                    points[i]->lineTo(scene,*(*l));
                    a.processEvents(); // show rendered line
                }
            }

        }


    }

    auto end = chrono::high_resolution_clock::now();
    cout << "Computing line segments took "
         << std::chrono::duration_cast<chrono::milliseconds>(end - begin).count()
         << " milliseconds." << endl;

    return a.exec();;
}
