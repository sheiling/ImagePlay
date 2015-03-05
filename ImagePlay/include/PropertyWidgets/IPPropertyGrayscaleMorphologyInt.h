#ifndef IPPROPERTYGRAYSCALEMORPHOLOGYINT_H
#define IPPROPERTYGRAYSCALEMORPHOLOGYINT_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QSpinBox>
#include <QComboBox>

#include <QDebug>

#include "IPPropertyWidget.h"

#include "IPPropertyKernelInt.h"

#include "IPKernelPreset.h"

class IPPropertyGrayscaleMorphologyInt : public IPPropertyWidget
{
    Q_OBJECT
public:
    IPPropertyGrayscaleMorphologyInt(IPLProcessPropertyVectorInt* property, QWidget *parent) : IPPropertyWidget(parent)
    {
        // init presets
        int presetEmpty[]       = {0,0,0,0,0,0,0,0,0};
        int presetSquare3[]     = {1,1,1,1,1,1,1,1,1};
        int presetSquare5[]     = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        int presetSquare7[]     = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        int presetSquare9[]     = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        int presetCross3[]      = {0,1,0,1,1,1,0,1,0};
        int presetCross5[]      = {0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0};
        int presetCross7[]      = {0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0};
        int presetCross9[]      = {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0};
        int presetDiagCross3[]  = {1,0,1,0,1,0,1,0,1};
        int presetDiagCross5[]  = {1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1};
        int presetDiagCross7[]  = {1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1};
        int presetDiagCross9[]  = {1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1};
        int presetDiamond5[]    = {0,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0};
        int presetDiamond7[]    = {0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0};
        int presetDiamond9[]    = {0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0};
        int presetDisk5[]       = {0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0};
        int presetDisk7[]       = {0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,0};
        int presetDisk9[]       = {0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0};

        // add to preset list
        _presets.push_back(IPKernelPreset("Custom",         presetEmpty, 9));
        _presets.push_back(IPKernelPreset("Square 3x3",     presetSquare3, 9));
        _presets.push_back(IPKernelPreset("Square 5x5",     presetSquare5, 25));
        _presets.push_back(IPKernelPreset("Square 7x7",     presetSquare7, 49));
        _presets.push_back(IPKernelPreset("Square 9x9",     presetSquare9, 81));
        _presets.push_back(IPKernelPreset("Cross 3x3",      presetCross3, 9));
        _presets.push_back(IPKernelPreset("Cross 5x5",      presetCross5, 25));
        _presets.push_back(IPKernelPreset("Cross 7x7",      presetCross7, 49));
        _presets.push_back(IPKernelPreset("Cross 9x9",      presetCross9, 81));
        _presets.push_back(IPKernelPreset("Diagonal Cross 3x3",presetDiagCross3, 9));
        _presets.push_back(IPKernelPreset("Diagonal Cross 5x5",presetDiagCross5, 25));
        _presets.push_back(IPKernelPreset("Diagonal Cross 7x7",presetDiagCross7, 49));
        _presets.push_back(IPKernelPreset("Diagonal Cross 9x9",presetDiagCross9, 81));
        _presets.push_back(IPKernelPreset("Diamond 5x5",    presetDiamond5, 25));
        _presets.push_back(IPKernelPreset("Diamond 7x7",    presetDiamond7, 49));
        _presets.push_back(IPKernelPreset("Diamond 9x9",    presetDiamond9, 81));
        _presets.push_back(IPKernelPreset("Disk 5x5",       presetDisk5, 25));
        _presets.push_back(IPKernelPreset("Disk 7x7",       presetDisk7, 49));
        _presets.push_back(IPKernelPreset("Disk 9x9",       presetDisk9, 81));

        // get property values
        _property = property;
        _kernel = ((IPLProcessPropertyVectorInt*) property)->value();

        _ignoreCombobox = false;

        _kernelType = 0;        // 3x3
        if(_kernel.size() == 25)
        {
            _kernelType = 1;    // 5x5
        }
        else if(_kernel.size() == 49)
        {
            _kernelType = 2;    // 7x7
        }
        else if(_kernel.size() == 81)
        {
            _kernelType = 3;    // 9x9
        }

        setLayout(new QVBoxLayout(this));
        _gridLayout = new QGridLayout;
        _gridLayout->setSpacing(2);

        _kernelWidget = new QWidget(this);
        _kernelWidget->setLayout(_gridLayout);
        layout()->addWidget(_kernelWidget );

        _kernelSizeComboBox = new QComboBox(this);
        _kernelSizeComboBox->addItem("3x3");
        _kernelSizeComboBox->addItem("5x5");
        _kernelSizeComboBox->addItem("7x7");
        _kernelSizeComboBox->addItem("9x9");
        _kernelSizeComboBox->setCurrentIndex(_kernelType);
        connect(_kernelSizeComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &IPPropertyGrayscaleMorphologyInt::enableDisableKernelEditor);

        layout()->addWidget(_kernelSizeComboBox);


        // compute offset
        int offset = 4-((int)sqrt((float)_kernel.size()) / 2);
        int j = 0;
        for(int i=0; i<81; i++)
        {
            int column = i%9;
            int row    = i/9;

            QSpinBox* input = new QSpinBox(this);
            input->setButtonSymbols(QAbstractSpinBox::NoButtons);
            input->setAlignment(Qt::AlignCenter);
            input->setFixedSize(QSize(18, 18));

            input->setMinimum(-9);
            input->setMaximum(9);

            if(column >= offset && row >= offset && column < 9-offset && row < 9-offset)
            {
                input->setValue(_kernel[j++]);
            }
            else
            {
                input->setValue(0);
            }

            _gridLayout->addWidget(input, i/9, i%9);
            _inputs.push_back(input);

            connect(input, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &IPPropertyGrayscaleMorphologyInt::updateValue );
        }

        _presetsComboBox = new QComboBox(this);
        for(size_t i=0; i<_presets.size(); i++)
        {
            _presetsComboBox->addItem(QString::fromStdString(_presets[i].name));
        }
        connect(_presetsComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &IPPropertyGrayscaleMorphologyInt::setKernelPreset);
        layout()->addWidget(_presetsComboBox);

        enableDisableKernelEditor();
        setKernelPreset();
    }

//    void

    void setMinimum(int)  {  }
    void setMaximum(int)  {  }
    std::vector<int> value()             { return _kernel; }

    void saveValue()        { _property->setValue(value()); }

signals:

public slots:
    void updateValue()
    {
        // any change should change the preset box to "Custom"
        if(!_ignoreCombobox)
            _presetsComboBox->setCurrentIndex(0);

        // clear old kernel
        _kernel.clear();

        int offset = 3;     // 3x3
        if(_kernelType == 1)
        {
            offset = 2;     // 5x5
        }
        else if(_kernelType == 2)
        {
            offset = 1;     // 7x7
        }
        else if(_kernelType == 3)
        {
            offset = 0;     // 9x9
        }

        // get all values from the active inputs
        for(int i=0; i<_inputs.size(); i++)
        {
            int column = i%9;
            int row    = i/9;

            if(column >= offset && row >= offset && column < 9-offset && row < 9-offset)
            {
                _kernel.push_back(_inputs[i]->value());
            }
        }

        if(_property)
            saveValue();

        emit changed();
    }

    void enableDisableKernelEditor()
    {
        _kernelType = _kernelSizeComboBox->currentIndex();

        int offset = 3;     // 3x3
        if(_kernelType == 1)
        {
            offset = 2;     // 5x5
        }
        else if(_kernelType == 2)
        {
            offset = 1;     // 7x7
        }
        else if(_kernelType == 3)
        {
            offset = 0;     // 9x9
        }

        for(int i=0; i<_inputs.size(); i++)
        {
            int column = i%9;
            int row    = i/9;

            if(column >= offset && row >= offset && column < 9-offset && row < 9-offset)
            {
                _inputs[i]->setEnabled(true);
            }
            else
            {
                _inputs[i]->setEnabled(false);
            }
        }
        updateValue();
    }

    void setKernelPreset()
    {
        int index = _presetsComboBox->currentIndex();

        // Custom should not overwrite the values
        if(index == 0)
        {
            return;
        }

        // compute offset
        int offset = 4-((int)sqrt((float)_presets[index].kernel.size()) / 2);

        // assign values to the input boxes
        int j = 0;
        _ignoreCombobox = true;
        for(int i=0; i<_inputs.size(); i++)
        {
            int column = i%9;
            int row    = i/9;

            if(column >= offset && row >= offset && column < 9-offset && row < 9-offset)
            {
                _inputs[i]->setValue(_presets[index].kernel[j++]);
            }
            else
            {
                _inputs[i]->setValue(0);
            }
        }
        updateValue();
        _ignoreCombobox = false;
    }

private:
    IPLProcessPropertyVectorInt*   _property;
    QGridLayout*                _gridLayout;
    std::vector<int>            _kernel;
    int                         _kernelType;        ///< 0=3x3, 1=5x5, 2=7x7 3=9x9
    QList<QSpinBox*>            _inputs;
    QComboBox*                  _presetsComboBox;
    QComboBox*                  _kernelSizeComboBox;
    QWidget*                    _kernelWidget;
    bool                        _ignoreCombobox;
    std::vector<IPKernelPreset> _presets;
};

#endif // IPPROPERTYGRAYSCALEMORPHOLOGYINT_H
