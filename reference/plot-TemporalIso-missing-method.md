# Plots for TemporalIso objects

Inherited from
[rstan-plotting-functions](https://mc-stan.org/rstan/reference/plotting-functions.html),
the default plot shows posterior uncertainty intervals and point
estimates of isotopic values for each interval. The plot method can also
regress to standard rstan methods.

## Usage

``` r
# S4 method for class 'TemporalIso,missing'
plot(x, ..., plotfun = "isotopic")
```

## Arguments

- x:

  TemporalIso: An instance of class TemporalIso, generated from
  [`estimateIntervals`](https://pandora-isomemo.github.io/OsteoBioR/reference/estimateIntervals.md)

- ...:

  Optional arguments to the plotting functions.

- plotfun:

  character: a character string specifying which plotting function is to
  be used. The default is "isotopic", whis is a
  [`stan_plot`](https://mc-stan.org/rstan/reference/stan_plot.html) only
  for the interval values. "stan_plot", "stan_trace", "stan_dens" etc
  regress to the functionality of rstan.

## Value

a ggplot object which can be further customized using the ggplot2
package.

## See also

[rstan-plotting-functions](https://mc-stan.org/rstan/reference/plotting-functions.html),
[rstan_gg_options](https://mc-stan.org/rstan/reference/stan_plot_options.html)
