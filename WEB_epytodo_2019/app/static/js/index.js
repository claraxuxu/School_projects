$(window).on('load',function() {
    $('#signin-modal').modal('show');
    $('#signup-modal').modal('hide');
});

function alternate() {
    if ($('#signin-modal').hasClass('show')) {
        $('#signin-modal').modal('hide');
        $('#signup-modal').modal('show');
    } else {
        $('#signup-modal').modal('hide');
        $('#signin-modal').modal('show');
    }
}

const signin = document.querySelector('#signin-form');
const signup = document.querySelector('#signup-form');

signin.addEventListener('submit', function (event) {
    event.preventDefault();
    const data = new FormData(event.target);
    let obj = {
        "username": data.get('user'),
        "password": data.get('mdp'),
    };
    fetch("/signin", {
        method: "POST",
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(obj),
    }).then(response => response.json())
    .then(json => {
        if (json && json.result == "signin successful") {
            document.cookie = "sessionID=" + json.sessionID;
            window.location.href = "/tasks";
        } else if (json && json.error == "login or password does not match") {
            alert(json.error);
        } else if (json && json.error == "internal error") {
            alert(json.error);
        } else {
            alert("timeout");
        }
    })
});

signup.addEventListener('submit', function (event) {
    event.preventDefault();
    const data = new FormData(event.target);
    let obj = {
        "username": data.get('user'),
        "password": data.get('mdp'),
    };
    fetch("/register", {
        method: "POST",
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(obj),
    }).then(response => response.json())
    .then(json => {
        if (json && json.result == "account created") {
            document.cookie = "sessionID=" + json.sessionID;
            window.location.href = "/tasks";
        } else if (json && json.error == "account already exists") {
            alert(json.error);
        } else if (json && json.error == "internal error") {
            alert(json.error);
        } else {
            alert("timeout");
        }
    })
});