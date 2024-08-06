const dateNow = new Date();
const dateNowStart = new Date(dateNow.toDateString());

function doAutocomplete(elem, entries, searchTerm) {
  // Clear everything
  while (elem.lastChild.id != "search-placeholder-item") {
    elem.lastChild.remove();
  }
  // Repopulate
  for (const ent of entries) {
    const matchIndex = ent.alt_title.toLowerCase().indexOf(searchTerm);

    let newElem = document.createElement("a");
    newElem.classList.add("nav-search-item");
    if (ent.data == "set") {
      newElem.setAttribute("href", "/hub/set/" + ent.shortname);
    } else if (ent.data == "problem") {
      newElem.setAttribute("href", "/problem/" + ent.shortname + "/");
    } else if (ent.data == "hof") {
      newElem.setAttribute("href", "/problem/" + ent.shortname + "/hof")
    } else if (ent.data == "submission") {
      newElem.setAttribute("href", "/problem/" + ent.shortname + "/submission/" + ent.id)
    }
    if (matchIndex != -1) {
      newElem.innerHTML = ent.alt_title.substring(0, matchIndex) + "<u>" + ent.alt_title.substring(matchIndex, matchIndex + searchTerm.length) + "</u>" + ent.alt_title.substring(matchIndex + searchTerm.length);
    } else {
      newElem.textContent = ent.alt_title;
    }
    newElem.title = ent.title;
    // Force hide the dropdown once clicked
    newElem.addEventListener("click", function() {
      newElem.parentElement.classList.add("hide-hover");
    });

    let icon = document.createElement("span");
    if (ent.data == "set") {
      icon.classList.add("fas");
      icon.classList.add("fa-cubes");
    } else if (ent.data == "problem") {
      icon.classList.add("fas");
      icon.classList.add("fa-cube");
    } else if (ent.data == "hof") {
      icon.classList.add("fas");
      icon.classList.add("fa-trophy");
    } else if (ent.data == "submission") {
      icon.classList.add("fas");
      icon.classList.add("fa-code");
    }
    icon.classList.add("mr-sm-1")
    newElem.prepend(icon);
    elem.append(newElem);
  }
}

prevSearchTerm = "";

scheduleAutoComplete = _.debounce(function() {
  const elem = document.getElementById("nav-search-input");
  const autocompleteDump = document.getElementById("search-suggestions");
  const searchTerm = elem.value;
  if (searchTerm != prevSearchTerm) {
      prevSearchTerm = searchTerm;
      // Search terms different, update stuff
      const req = new XMLHttpRequest();
      req.open("GET", "/api/search/?q=" + searchTerm);
      req.onload = function() {
        let entries = [];
        res = JSON.parse(req.response);
        if (!res.matches) {
          res.matches = [];
        }
        doAutocomplete(autocompleteDump, res.matches, searchTerm);
      };
      req.send();
  }
  scheduleAutoComplete.cancel()
}, 200);

// Convert all time tags to localtime and set inner text content
window.addEventListener("load", function(ev) {
    for (let x of document.getElementsByTagName("time")) {
        let noCap = x.classList.contains("no-capital");
        let date = new Date(x.getAttribute("datetime"));
        let msDiff = date - dateNowStart;
        let dateString = date.toLocaleDateString("en-AU", { year: 'numeric', month: 'numeric', day: 'numeric' });
        if (msDiff >= 0) {
            dateString = noCap ? "today" : "Today";
        } else if (msDiff >= -86400000) {
            dateString = noCap ? "yesterday" : "Yesterday";
        }
        let timeString = date.toLocaleTimeString("en-AU", { timeStyle: "short" });
        x.textContent = dateString + " at " + timeString;
    }
});

/*
 This allows us to display a short explanatio when a language is chosen for submission
 Currently, this gives a description for java and python
 */ 

function updateLanguageDescription() {
  var select = document.getElementById("id_language");
  var description = document.getElementById("languageDescription");

  var descriptions = {
      "JAVA": "<p style=\"margin-top: 0.5em;\">Java solutions should be in a class called <code>Solution</code> and must be run from the routine <code>public static void main(String[] args)</code> within this <code>Solution</code> class.</p>",
      "PY3": "<p style=\"margin-top: 0.5em;\">Code in python runs slower than other languages. To ensure fairness, python submissions have an increased time limit.</p>"
  };

  var selectedLanguage = select.value;
  if (descriptions[selectedLanguage]) {
      description.innerHTML = descriptions[selectedLanguage];
      description.style.display = "block";
  } else {
      description.style.display = "none";
  }
}
