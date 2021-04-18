const form = document.querySelector('#task-form');
const statusCode = document.querySelector("#statusCode").value;

if (statusCode == "401") {
    alert("you must be logged in");
    document.cookie = "";
    window.location.href = '/';
} else if (statusCode == "500") {
    alert("internal error");
} else if (statusCode != "200") {
    alert('timeout');
}

if (!document.cookie.startsWith("sessionID=")) {
    window.location.href = '/';
}

function disconnect() {
    fetch("/signout", {
        method: "POST",
        headers: {
            'Accept': 'application/json',
        }
    }).then(response => response.json())
    .then(json => {
        if (json && json.result == "signout successful") {
            document.cookie = "";
            window.location.href = '/';
        } else if (json && json.error == "internal error") {
            alert(json.error);
        } else {
            alert('timeout');
        }
    });
}

form.addEventListener('submit', function (event) {
    event.preventDefault();
    const data = new FormData(event.target);
    let obj = {
        "title": data.get('project_name'),
        "begin": data.get('start_date').replace('T', ' '),
        "end": data.get('end_date').replace('T', ' '),
        "status": data.get("statut").toLowerCase()
    };
    fetch("/user/task/add", {
        method: "POST",
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(obj)
    }).then(response => response.json())
    .then(json => {
        console.log(json);
        if (json && json.result == "new task added") {
            document.location.reload(true);
        } else if (json && json.error == "internal error") {
            alert(json.error);
        } else if (json && json.error == "you must be logged in") {
            alert(json.error);
            document.cookie = "";
            window.location.href = '/';
        } else {
            alert('timeout');
        }
    });
});