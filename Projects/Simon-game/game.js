
var gamePattern=[];
var level=0;
var userClickedPattern=[];
var buttonColours=["red", "blue", "green", "yellow"];
var started = false;
var i=0;

$(document).keypress(function(){

  if(!started){
    $("#level-title").text("Level " + level);
    nextSequence();
    started=true;
    }
  });

$(".btn").click(function(){
  var userChosenColour = $(this).attr("id");
             userClickedPattern.push(userChosenColour);
             console.log(userClickedPattern);
       playSound(userChosenColour);
       animatePress(userChosenColour);
      checkAnswer(userClickedPattern);

});

function playSound(name){
  var audio=new Audio("sounds/"+name+".mp3")
  audio.play();

}
function animatePress(name){
  $("#"+name).addClass("pressed");
    setTimeout(function(){ document.querySelector("#"+name).classList.remove("pressed"); },100);
}


function checkAnswer(){

     if(userClickedPattern[i]!=gamePattern[i]){

       var audio=new Audio("sounds/wrong.mp3")
       audio.play();
       $("body").addClass("game-over");
    $("#level-title").text("Game Over, Press Any Key to Restart");

    setTimeout(function () {
      $("body").removeClass("game-over");
    }, 200);
startOver();

     }

     if(gamePattern.length===userClickedPattern.length)
     {

         setTimeout(function () {
            nextSequence();
          }, 1000);

     }
i=i+1;

 }

 function nextSequence(){
i=0;
 level=level+1;
userClickedPattern=[];
   $("h1").text("LEVEL "+level);
   var randomNumber=Math.floor(Math.random()*4);
   var randomChosenColour=buttonColours[randomNumber];
   gamePattern.push(randomChosenColour);
     $("#"+randomChosenColour).fadeIn(100).fadeOut(100).fadeIn(100);
     playSound(randomChosenColour);

 }
 function startOver(){
     gamePattern=[];
     started=false;
   level=0;
 }
