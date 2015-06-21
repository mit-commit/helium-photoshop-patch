
#target photoshop

// Helper function for calculating standard deviation
function getDev(list, mean){
    var x = 0
    for(var i =0; i<list.length; i++){
        x = x + (list[i] - mean)*(list[i]-mean)
    }
    return Math.sqrt(x/list.length)
}

// ID of the "Dissolve" plugin
var id = stringIDToTypeID( "d9543b0c-3c91-11d4-97bc-00b0d0204936" );

// Stuff to call Boxblur (taken from some tutorial online)
var idboxblur = stringIDToTypeID( "boxblur" );
var desc2 = new ActionDescriptor();
var idRds = charIDToTypeID( "Rds " );
var idPxl = charIDToTypeID( "#Pxl" );
desc2.putUnitDouble( idRds, idPxl, 11.000000 );

var layer = app.activeDocument.activeLayer;
var warmupIterations = 10, iterations = 30;

function doStuff() {
    //layer.applyBlur();
    //layer.applyBlurMore();
    //layer.applySharpen();
    //layer.applySharpenMore();
    //layer.invert();
    //layer.threshold(128);
    //layer.applyDespeckle();
    //layer.applyAddNoise(12.5, NoiseDistribution.UNIFORM, false);
    //layer.applySharpenEdges();
    //layer.equalize();
    //layer.adjustBrightnessContrast(50, 0);
    //layer.adjustBrightnessContrast(0, 50);
    //layer.adjustBrightnessContrast(50, 50);
    //executeAction( idboxblur, desc2, DialogModes.NO );
    //layer.applyGaussianBlur(1.0);
}

for (var i = 0; i < warmupIterations; i++) {
    doStuff();
}

var times = []
var sum = 0
//~ Apply Photoshop Filter      
for(var i = 0; i < iterations; i++){
    var now = new Date().getTime()
    doStuff();
    var after = new Date().getTime()
    times.push(after - now)
    sum = sum + (after - now)
}

// times contains individual times. sum contains sum of individual times
var ps_time = sum / iterations
var ps_dev = getDev(times, ps_time)
var timeString = ps_time + " pm "+ps_dev;
for (var i = 0; i < iterations; i++) {
    timeString = timeString + "\t"+times[i];
}
alert(timeString);
var file = File("C:\\Users\\kevin\\Desktop\\scripttime.txt");
file.encoding = "UTF8";
file.open("a");
file.writeln(timeString);
file.close();


// Alert all the individual times
//for(var i =0; i< iterations; i++){
    //alert(times[i])
//}


// STUFF TO TIME HALIDE FUNCTION

//~   var times = []
//~   var sum = 0
//~   for(var i = 0; i<iterations; i++){
//~         var now = new Date().getTime()
//~          executeAction( id, undefined, DialogModes.NO );
//~         var after = new Date().getTime()
//~         times.push(after - now)
//~         sum = sum + (after - now)
//~  }
//~  var halide_time = sum / iterations
//~  var halide_dev = getDev(times, halide_time)
 
//~  alert('Halide took: ')
//~  alert(halide_time)
//~  alert(halide_dev)
//~   for(var i =0; i< iterations; i++){
//~         alert(times[i])
//~       }
