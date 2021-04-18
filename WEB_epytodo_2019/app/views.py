from flask import render_template, request, jsonify
from app.controller import register, signin, signout, user_info, user_tasks, get_task, update_task, create_task, delete_task
from app import app

@app.errorhandler(404)
def page_not_found(error):
    return "Page not found!", 404

@app.route('/', methods=['GET'])
def route_home():
    return render_template("index.html")

@app.route('/tasks')
def route_tasks():
    json, statusCode = route_user_tasks()
    if statusCode != 200:
        array = []
    else:
        array = list(map(lambda x: list(x.values())[0], json['result']['tasks']))
    return render_template("task.html",  tasks=array, statusCode=statusCode), statusCode

@app.route('/register', methods=['POST'])
def route_register():
    json = request.get_json()
    username, password, keys = json['username'], json['password'], json
    response, statusCode = register(username, password, keys)
    return response, statusCode

@app.route('/signin', methods=['POST'])
def route_signin():
    json = request.get_json()
    username, password = json['username'], json['password']
    response, statusCode = signin(username, password)
    return response, statusCode

@app.route('/signout', methods=['POST'])
def route_signout():
    sessionID = request.cookies.get('sessionID')
    response, statusCode = signout(sessionID)
    return response, statusCode

@app.route('/user', methods=['GET'])
def route_user():
    sessionID = request.cookies.get('sessionID')
    response, statusCode = user_info(sessionID)
    return response, statusCode

@app.route('/user/task', methods=['GET'])
def route_user_tasks():
    sessionID = request.cookies.get('sessionID')
    response, statusCode = user_tasks(sessionID)
    return response, statusCode

@app.route('/user/task/<id>', methods=['GET'])
def route_task_info(task_id):
    sessionID = request.cookies.get('sessionID')
    response, statusCode = get_task(sessionID, task_id)
    return response, statusCode

@app.route('/user/task/<id>', methods=['POST'])
def route_update_task(task_id):
    taskObj = request.get_json()
    sessionID = request.cookies.get('sessionID')
    response, statusCode = update_task(sessionID, task_id, taskObj)
    return response, statusCode

@app.route('/user/task/add', methods=['POST'])
def route_add_task():
    taskObj = request.get_json()
    sessionID = request.cookies.get('sessionID')
    response, statusCode = create_task(sessionID, taskObj)
    return response, statusCode

@app.route('/user/task/del/<id>', methods=['POST'])
def route_del_task(task_id):
    sessionID = request.cookies.get('sessionID')
    response, statusCode = delete_task(sessionID, task_id)
    return response, statusCode