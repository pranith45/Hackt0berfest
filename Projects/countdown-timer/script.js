const daysEl = document.getElementById("days");
const hoursEl = document.getElementById("hours");
const minsEl = document.getElementById("mins");
const secondsEl = document.getElementById("seconds");

const neetDate = "12 Sept 2021";

let examOver = false;

function countdown() {
  const neet2021Date = new Date(neetDate);
  const currentDate = new Date();

  const totalSeconds = (neet2021Date - currentDate) / 1000; // Returns total no of milisec between two dates

  const days = Math.floor(totalSeconds / 3600 / 24);
  const hours = Math.floor(totalSeconds / 3600) % 24;
  const mins = Math.floor(totalSeconds / 60) % 60;
  const seconds = Math.floor(totalSeconds) % 60;

  if (days >= 0 && hours >= 0 && mins >= 0 && seconds >= 0) {
    daysEl.innerHTML = days;
    hoursEl.innerHTML = formatTime(hours);
    minsEl.innerHTML = formatTime(mins);
    secondsEl.innerHTML = formatTime(seconds);
  } else {
    daysEl.innerHTML = "0";
    hoursEl.innerHTML = "0";
    minsEl.innerHTML = "0";
    secondsEl.innerHTML = "0";
    examOver = true;
    document.querySelector("body").classList.add("EObody");
    document.querySelector("h1").classList.add("EOh1");
    const EOspan = document.querySelectorAll("span");
    EOspan.forEach((span) => span.classList.add("EOspan"));
    const EOp = document.querySelectorAll("p");
    EOp.forEach((p) => p.classList.add("EOp"));
  }
}

function formatTime(time) {
  return time < 10 ? `0${time}` : time;
}

// initial call
countdown();

setInterval(countdown, 1000);

if (examOver) {
  const newH1 = document.createElement("h1");
  newH1.innerText = "Exams Over Enjoy Your Vacation";
  document.querySelector(".container").append(newH1);
  console.dir(newH1);
  newH1.style.color = "#efefef";
}
