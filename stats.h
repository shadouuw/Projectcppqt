#ifndef STATS_H
#define STATS_H
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>

class stats
{
public:
    stats();
   void Loaddata();
private :

  QtCharts::QChartView* chartview;
  QtCharts::QBarSeries *barseries;


};

#endif // STATS_H
