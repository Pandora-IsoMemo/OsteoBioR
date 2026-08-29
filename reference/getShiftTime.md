# Calculate time points of shifted isotopic values

The function calculates points in time where large changes happen in the
isotopic values. It uses the posterior distributions to estimate the
probability of changes to be (absolutely or relatively) large.

## Usage

``` r
getShiftTime(
  object,
  type = TRUE,
  slope = FALSE,
  threshold = NULL,
  probability = 0.5
)
```

## Arguments

- object:

  model of class
  [`TemporalIso`](https://pandora-isomemo.github.io/OsteoBioR/reference/TemporalIso-class.md)

- type:

  boolean If the calculation shall be based on absolute or relative
  differences. Defaults to TRUE

- slope:

  boolean If the calculation shall be based on differences or slopes
  Defaults to FALSE (differences)

- threshold:

  numeric. The threshold for a shift to be considered "large". Defaults
  to 1.5 for absolute isotopic values and 15 percent for relative
  changes.

- probability:

  the probability for the differences to be larger than the threshold.
  Defaults to 50 percent.

## Value

a data.frame containing the interval starts (intStart) and ends (intEnd)
of changes.
