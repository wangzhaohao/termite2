#pragma once
#include "Kernel.h"

class ConcentrationConvectionSource : public Kernel
{
public:
  static InputParameters validParams();

  ConcentrationConvectionSource(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

private:
  const VariableValue & _temp;
  const VariableGradient & _grad_temp;
};

