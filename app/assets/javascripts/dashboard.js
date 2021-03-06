$(document).ready(function(){

  var ctx = $("#graph").get(0).getContext("2d");

  var blankLabels = [];
  for (var i = 0; i < 50; i++) {
    blankLabels.push("");
  }

  $('#import').click(importValues);

  function importValues(){
    $.get('/import_values.json').done(function(data){
      $('#average').empty();
      $('#max').empty();
      $('#min').empty();

      $('#average').append(data.average);
      $('#max').append(data.max);
      $('#min').append(data.min);

      drawGraph(data.values);
    });
  }

  function drawGraph(values){

    var data = {
      labels : blankLabels,
      datasets : [
        {
          fillColor   : "#F00A0A",
          strokeColor : "darkred",
          pointColor  : "white",
          pointStrokeColor : "grey",
          data : values
        }
      ]
    }

    var graph = new Chart(ctx).Line(data);
  }

});