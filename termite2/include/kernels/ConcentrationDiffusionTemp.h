#pragma once
#include "Kernel.h"

class ConcentrationDiffusionTemp : public Kernel
{
public:
    static InputParameters validParams();

    ConcentrationDiffusionTemp(const InputParameters & paramters);

protected:
    virtual Real computeQpResidual() override;

private:

    const VariableValue & _temp;
    const VariableSecond & _second_temp;
};

