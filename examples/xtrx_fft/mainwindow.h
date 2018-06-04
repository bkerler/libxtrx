/*
 * xtrx high level demo file
 * Copyright (c) 2018 Sergey Kostanbaev <sergey.kostanbaev@fairwaves.co>
 * For more information, please visit: http://xtrx.io
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <xtrx_api.h>

namespace Ui {
class MainWindow;
}

class RxThread;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


	QVector<double> x;

	QVector<double> y1;
	QVector<double> y2;
	QVector<double> y3;
	QVector<double> y4;

	QVector<double> z1;
	QVector<double> z2;
	QVector<double> z3;
	QVector<double> z4;

	xtrx_dev* dev;

	bool draw_max;

	void wf_add_point(int x, unsigned data);
	void wf_feed_line();

public slots:
	void redraw(int);
	void on_btStartStop_clicked();
	void on_rescale_clicked();
	void on_max_clicked();

	void on_freq_valueChanged(double);
	void on_bw_valueChanged(double);
	void on_gain_valueChanged(int);

	void on_fft_avg_valueChanged(int);
	void on_fft_skip_valueChanged(int);

	void on_lna_currentIndexChanged(int);

	void on_throttle_valueChanged(int);

public:
//private:
    Ui::MainWindow *ui;
	RxThread* rx_thread;
};

#endif // MAINWINDOW_H
