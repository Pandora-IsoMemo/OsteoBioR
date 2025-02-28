getStyleForIndividuals <- function(pointStyleList, input) {
  # pointStyleList are reactive values -> lapply over the names and not(!) the list itself
  style <- lapply(names(pointStyleList), function(x) {pointStyleList[[x]][input]}) %>% 
    unlist()
  names(style) <- names(pointStyleList)
  
  style
}

getDefaultPointFormatForModels <- function(pointStyleList, modelNames) {
  # default colours
  defaultColours <- ggplot2::scale_color_discrete()$palette(n = length(modelNames))
  names(defaultColours) <- modelNames
  
  # setup lists with default values for style specs
  for (i in modelNames) {
    if (is.null(pointStyleList[[i]])) 
      pointStyleList[[i]] <- config()[["defaultPointStyle"]][["dataPoints"]]
    # use default colour per model
    pointStyleList[[i]]["color"] <- defaultColours[i]
  }
  
  return(pointStyleList)
}

getDefaultTextFormat <- function() {
  list(legendTitle  = config()[["defaultIntervalTimePlotTitle"]],
       legendText  = config()[["defaultIntervalTimePlotText"]],
       plotTitle  = config()[["defaultIntervalTimePlotTitle"]],
       xAxisTitle = config()[["defaultIntervalTimePlotTitle"]],
       yAxisTitle = config()[["defaultIntervalTimePlotTitle"]],
       yAxisTitle2 = config()[["defaultIntervalTimePlotTitle"]],
       xAxisText  = config()[["defaultIntervalTimePlotText"]],
       yAxisText  = config()[["defaultIntervalTimePlotText"]],
       yAxisText2  = config()[["defaultIntervalTimePlotText"]])
}
