[![Build Status](http://jenkins.subversiverobotics.com/buildStatus/icon?job=lit/master)](https://jenkins.subversiverobotics.com/blue/organizations/jenkins/lit/activity)

# Lightweight Information Theory Library
Lit is entirely templates, to use it just include the appropriate
header.

The easiest way to use `lit` is to download it (or make it a
submodule) and add `lit/include` to the include path for your project.

## Entropy

```c++
#include <entropy.hpp>
```

Exposes functions templates to compute entropy, conditional entropy,
and joint entropy or a sample/samples from a *discrete* random variable.

```c++
template <typename A>
double entropy(std::vector<A>& rv);

/**
 * 'a' and 'b' must be the same length. If they are not then an
 * 'invalid_argument exception will be thrown.
 */
template <typename A, typename B>
double joint_entropy(std::vector<A>& a, std::vector<B>& b);

/**
 * Again, 'a' and 'b' must be the same length.
 */
template <typename A, typename B>
double conditional_entropy(std::vector<A>& a, std::vector<B>& b);
```

These templates should work with any types, as long as the type can be
compared for equality.

## Mutual Information
*coming soon*

## Transfer Entropy
*coming ... eventually*
