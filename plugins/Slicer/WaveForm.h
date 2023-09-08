#include <QApplication>
#include <QFontMetrics>
#include <QInputDialog>
#include <QMouseEvent>
#include <QPainter>

#include "SampleBuffer.h"

#ifndef WAVEFORM_H
#define WAVEFORM_H

namespace lmms
{

class SlicerT;

namespace gui
{


class WaveForm : public QWidget {
    	Q_OBJECT
    protected:
        virtual void mousePressEvent( QMouseEvent * _me );
        virtual void mouseReleaseEvent( QMouseEvent * _me );
        virtual void mouseMoveEvent( QMouseEvent * _me );
        virtual void mouseDoubleClickEvent(QMouseEvent * _me);

        virtual void keyPressEvent(QKeyEvent * ke);

        virtual void paintEvent( QPaintEvent * _pe);

    private:
        int width;
        int height;
        float seekerRatio = 0.3f;
        int margin = 5;
        QColor waveformBgColor = QColor(11, 11, 11);
        QColor waveformColor = QColor(124, 49, 214);
        QColor playColor = QColor(255, 255, 255, 200);
        QColor playHighlighColor = QColor(255, 255, 255, 70);
        QColor sliceColor = QColor(49, 214, 124);
        QColor selectedSliceColor = QColor(172, 236, 190);
        QColor seekerColor = QColor(214, 124, 49);
        QColor seekerShadowColor = QColor(0, 0, 0, 175);

        enum class draggingTypes {
            nothing,
            seekerStart,
            seekerEnd,
            seekerMiddle,
            slicePoint,
        };
        draggingTypes currentlyDragging;
        bool isDragging = false;

        float seekerStart = 0;
        float seekerEnd = 1;
        float seekerMiddle = 0.5f;
        int sliceSelected = 0;

        float noteCurrent;
        float noteStart;
        float noteEnd;

        QPixmap sliceEditor;
        QPixmap seeker;

        SampleBuffer currentSample;

        void drawEditor();
        void drawSeeker();
        void updateUI();

    public slots:
        void updateData();
        void isPlaying(float current, float start, float end);

    public:
        WaveForm(int _w, int _h, SlicerT * _instrument, QWidget * _parent);

    private:
        SlicerT * slicerTParent;
        std::vector<int> & slicePoints;

};
}}


#endif