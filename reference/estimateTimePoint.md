# Function to estimate isotopic value for specific time point(s)

Once the isotopic values in time course are estimated along with
estimateIntervals(), this function provides an interface to extract the
mean, standard deviation and quantiles for a specific point in time

## Usage

``` r
estimateTimePoint(object, time, intervalProb = 0.95)
```

## Arguments

- object:

  An object of class
  [TemporalIso](https://pandora-isomemo.github.io/OsteoBioR/reference/TemporalIso-class.md)
  fitted with estimateIntervals()

- time:

  A vector of numerics, indicating the point in time to extract
  estimates

- intervalProb:

  A numeric between 0 and 1 indicating the coverage of the credible
  interval

## Value

A data.frame with time points and their means, standard deviations and
credible intervals
