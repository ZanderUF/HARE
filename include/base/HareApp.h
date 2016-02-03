#ifndef HAREAPP_H
#define HAREAPP_H

#include "MooseApp.h"

class HareApp;

template<>
InputParameters validParams<HareApp>();

class HareApp : public MooseApp
{
public:
  HareApp(InputParameters parameters);
  virtual ~HareApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HAREAPP_H */
