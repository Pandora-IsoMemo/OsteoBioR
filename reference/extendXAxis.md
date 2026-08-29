# Extend X Axis

Add breaks and labels for x axis

## Usage

``` r
extendXAxis(xAxisData, xLabelLim, extendLabels = FALSE)
```

## Arguments

- xAxisData:

  (data.frame) data.frame containing "time", "lower" and "upper" columns
  used for the x axis.

- xLabelLim:

  numeric vector of length 2: range of labels of x axis

- extendLabels:

  (logical) if TRUE then extend the labels of the x axis
