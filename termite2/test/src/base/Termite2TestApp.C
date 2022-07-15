//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "Termite2TestApp.h"
#include "Termite2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
Termite2TestApp::validParams()
{
  InputParameters params = Termite2App::validParams();
  return params;
}

Termite2TestApp::Termite2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  Termite2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

Termite2TestApp::~Termite2TestApp() {}

void
Termite2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  Termite2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"Termite2TestApp"});
    Registry::registerActionsTo(af, {"Termite2TestApp"});
  }
}

void
Termite2TestApp::registerApps()
{
  registerApp(Termite2App);
  registerApp(Termite2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
Termite2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Termite2TestApp::registerAll(f, af, s);
}
extern "C" void
Termite2TestApp__registerApps()
{
  Termite2TestApp::registerApps();
}
