# server funtion of modelSpecifications module

server funtion of modelSpecifications module

## Usage

``` r
modelSpecificationsServer(
  id,
  dataMatrix,
  uploadedModelSpecInputs = reactiveVal()
)
```

## Arguments

- id:

  An ID string that corresponds with the ID used to call the module's UI
  function.

- dataMatrix:

  (reactive) shinyMatrix matrixInput, see
  [`estimateIntervals`](https://pandora-isomemo.github.io/OsteoBioR/reference/estimateIntervals.md):
  specifying the renewal rates of different probes for each time
  interval. The renewalRates should be between 0 and 100 (percentages).
  The dataframe should include a column specifying a time-index (e.g. 1,
  2, 3, ...) as well as columns for the different bones. The renewal
  rates should contain the times of origin, containing 100.

- uploadedModelSpecInputs:

  (reactive) modelSpecifications for the current fit
