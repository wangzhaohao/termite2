#pragma once
#include "IntegratedBC.h"

class ConvectionConcentrationBC : public IntegratedBC
{
public:
  static InputParameters validParams();

  ConvectionConcentrationBC(const InputParameters & parameters);
protected:
  virtual Real computeQpResidual() override;

private:

  const VariableValue & _temp;
  const VariableGradient & _grad_temp;
};

