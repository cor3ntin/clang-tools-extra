.. title:: clang-tidy - misc-comma-in-subscript-operator

misc-comma-in-subscript-operator
================================

Detect the use of the ``,`` operator in subscript expressions.

Example:

.. code-block:: c++

  //Use of a comma operator in a subscript expression
  //May no meet expectations
  foo[x,y];

  //OK
  foo[(x,y)];

