#pragma once

#include "Kernel.h"

class ConcentrationConvection : public Kernel
{
public:
    static InputParameters validParams();

    ConcentrationConvection(const InputParameters & parameters);

protected:
    virtual Real computeQpResidual() override;

    
private:

    const VariableValue & _temp;
    const VariableGradient & _grad_temp;
};
