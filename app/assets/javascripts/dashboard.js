importValues = function(){
  $.get('/import_values.json').done(function(data){
    $('#dashboard').empty()
    $('#dashboard').append(data);
  });
}