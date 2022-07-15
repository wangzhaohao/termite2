#pragma once
#include "Kernel.h"

class ConcentrationConvectionTemp : public Kernel
{
public:
    static InputParameters validParams();

    ConcentrationConvectionTemp(const InputParameters & parameters);

protected:
    virtual Real computeQpResidual() override;

private:

    const VariableValue & _temp;
    const VariableGradient & _grad_temp;
};

