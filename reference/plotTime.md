# Plot of credibility intervals for each time interval, plotted as timeseries

The function plots the credibility intervals for each time interval and
returns a ggplot object, which is further customizable.

## Usage

``` r
plotTime(
  object,
  prop = 0.8,
  plotShifts = FALSE,
  yLim = c(0, 1),
  xLim = c(0, 1),
  deriv = "1",
  color = NULL,
  alphaL = 0.9,
  alphaU = 0.1,
  sizeTextY = 12,
  sizeTextX = 12,
  sizeAxisX = 12,
  sizeAxisY = 12,
  secAxis = FALSE,
  xAxisLabel = "Time",
  yAxisLabel = "Estimate",
  extendLabels = FALSE,
  pointStyle = config()[["defaultPointStyle"]],
  ...
)
```

## Arguments

- object:

  model of class
  [`TemporalIso`](https://pandora-isomemo.github.io/OsteoBioR/reference/TemporalIso-class.md)

- prop:

  double between 0 and 1: length of credibility interval. The default
  value is 80 percent.

- plotShifts:

  boolean if shifts shall be marked or not. Defaults to False.

- yLim:

  numeric vector of length 2: range of y axis

- xLim:

  numeric vector of length 2: range of x axis

- deriv:

  character "1" for absolute values, "2" for first differences

- color:

  color of line and uncertainty region (RGB)

- alphaL:

  opacity line

- alphaU:

  opacity uncertainty region

- sizeTextY:

  size plot y label

- sizeTextX:

  size text x label

- sizeAxisX:

  size text x axis label

- sizeAxisY:

  size text y axis label

- secAxis:

  boolean secondary axis on right side?

- xAxisLabel:

  character label x-axis

- yAxisLabel:

  character label y-axis

- extendLabels:

  boolean if TRUE, extend the labels of the x-axis to the x-axis limits.
  If FALSE, the range of the data defines the range of x-axis labels.

- pointStyle:

  (list) named list with style definitions, or output of
  `plotPointsServer`

- ...:

  arguments handed to
  [`getShiftTime`](https://pandora-isomemo.github.io/OsteoBioR/reference/getShiftTime.md)

## Value

a [ggplot](https://ggplot2.tidyverse.org/reference/ggplot.html) object.
