# Get Plot Data

Extracts data from model output object

## Usage

``` r
getPlotData(object, prop = 0.8, time = NULL, deriv = "1")
```

## Arguments

- object:

  model of class
  [`TemporalIso`](https://pandora-isomemo.github.io/OsteoBioR/reference/TemporalIso-class.md)

- prop:

  double between 0 and 1: length of credibility interval. The default
  value is 80 percent.

- time:

  (numeric) time vector

- deriv:

  character "1" for absolute values, "2" for first differences
