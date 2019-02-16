model check helpers
===================

This library provides some simple helpers for model checking using
[CBMC][cbmc-link].  Specifically, this library provides the `MODEL_ASSERT` macro
which allows static assertions to be added to a program or library that are only
evaluated at model checking time.  Additionally, this library provides some
default shadowing capabilities to inject slightly different behavior than is
used by CBMC.  For instance, a non-deterministic `malloc` is provided which may
fail and return `NULL`.  As this failure case is possible in systems with
aggressive ulimit rules or embedded constraints, it is often desirable to model
cases where dynamic memory allocation fails.

[cbmc-link]: https://www.cprover.org/cbmc
