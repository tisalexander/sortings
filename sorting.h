#ifndef SORTINGS_SORTING_H
#define SORTINGS_SORTING_H

#include <QMap>
#include <QVector>

class QThread;
class SortingWorker;

enum SortingType {
	SortingTypeNotDefined = 0,
	Bubble
};

/*------- Sorting ---------------------------------------*/
class Sorting
{
public:
	Sorting();
	~Sorting();

public slots:
	void start();

signals:
	void finished();

private:
	QThread *m_pThread;
	SortingWorker *m_pWorker;
};

/*------- SortingWorker ---------------------------------*/
class SortingWorker
{
public:
	SortingWorker();
	~SortingWorker();

private:
	QVector<SortingType> m_sortingTypes;
	QVector<int> m_counts;
	QMap<SortingType, QVector<double>> m_results;
};

#endif // SORTINGS_SORTING_H
