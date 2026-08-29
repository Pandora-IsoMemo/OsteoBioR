# Calculate estimated stay times for locations given isotopic values

The function calculates points in time where large changes happen in the
isotopic values. It uses the posterior distributions to estimate the
probability of changes to be (absolutely or relatively) large.

## Usage

``` r
getSiteStayTimes(
  object,
  siteMeans,
  siteSigma,
  intervalLengths = NULL,
  print = TRUE
)
```

## Arguments

- object:

  model of class
  [`TemporalIso`](https://pandora-isomemo.github.io/OsteoBioR/reference/TemporalIso-class.md)

- siteMeans:

  numeric vector. Isotopic mean values of sites/locations.

- siteSigma:

  numeric vector. Isotopic standard deviation values of
  sites/locations..

- intervalLengths:

  numceric vector. Vector of time interval lengths. Optional (if not
  given equal length intervals are assumed)

- print:

  boolean. If output should be printed. Defaults to TRUE.

## Value

a data.frame containing the interval starts (intStart) and ends (intEnd)
of changes.
