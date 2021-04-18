from secrets import token_urlsafe
from json import loads
from app.models import user, task

def create_error(data):
    return { "error": data }

def create_result(data):
    return { "result": data }

def signin(username, password):
    user_class = user(username, password, "")
    ret = user_class.checkInvalidCredentials()
    if (ret < 0):
        user_class.conn.close()
        return ((create_error("login or password does not match"), 401) if ret == -1 else (create_error("internal error"), 500))
    user_class.sessionID = token_urlsafe(32)
    ret = user_class.submitSessionID()
    max_tries = 10
    try_count = 0
    while ret == -1 and try_count < max_tries:
        user_class.sessionID = token_urlsafe(32)
        try_count += 1
        ret = user_class.submitSessionID()
    user_class.conn.close()
    if try_count == max_tries or ret < 0:
        return create_error("internal error"), 500
    return dict(create_result("signin successful"), **{ "sessionID": user_class.sessionID }), 200

def register(username, password, keys):
    user_class = user(username, password, "")
    ret = user_class.registerUser(keys)
    if (ret < 0):
        user_class.conn.close()
        return ((create_error("account already exists"), 403) if ret == -1 else (create_error("internal error"), 500))
    user_class.sessionID = token_urlsafe(32)
    ret = user_class.submitSessionID()
    max_tries = 10
    try_count = 0
    while ret == -1 and try_count < max_tries:
        user_class.sessionID = token_urlsafe(32)
        try_count += 1
        ret = user_class.submitSessionID()
    user_class.conn.close()
    if try_count == max_tries or ret < 0:
        return create_error("internal error"), 500
    return dict(create_result("account created"), **{ "sessionID": user_class.sessionID }), 200

def signout(sessionID):
    user_class = user("", "", sessionID)
    ret = user_class.signoutUser()
    user_class.conn.close()
    if ret < 0:
        return create_error("internal error"), 500
    return create_result("signout successful"), 200

def user_info(sessionID):
    user_class = user("", "", sessionID)
    ret, keys = user_class.getUserInfo()
    user_class.conn.close()
    if ret < 0:
        return ((create_error("you must be logged in"), 401) if ret == -1 else (create_error("internal error"), 500))
    return create_result(loads(keys)), 200

def user_tasks(sessionID):
    task_class = task(sessionID)
    ret, tasks = task_class.getAllTasks()
    task_class.conn.close()
    if ret < 0:
        return ((create_error("you must be logged in"), 401) if ret == -1 else (create_error("internal error"), 500))
    new_tasks = []
    for _task in tasks:
        new_tasks.append({str(_task[0]): {
            "title": _task[1],
            "begin": _task[2],
            "end": _task[3],
            "status": _task[4]
        }})
    return create_result({"tasks": new_tasks}), 200

def get_task(sessionID, taskID):
    task_class = task(sessionID)
    ret, tasks = task_class.getTaskById(taskID)
    task_class.conn.close()
    if ret == -1:   return create_error("you must be logged in"), 401
    elif ret == -2: return create_error("internal error"), 500
    elif ret == -3: return create_error("task id does not exist"), 404
    del tasks['task_id']
    return create_result(tasks), 200

def update_task(sessionID, taskID, taskObj):
    task_class = task(sessionID)
    ret = task_class.updateTaskById(taskID, taskObj)
    task_class.conn.close()
    if ret == -1:   return create_error("you must be logged in"), 401
    elif ret == -2: return create_error("internal error"), 500
    elif ret == -3: return create_error("task id does not exist"), 404
    return create_result("update done"), 200

def create_task(sessionID, taskObj):
    task_class = task(sessionID)
    ret = task_class.createTask(taskObj)
    task_class.conn.close()
    if ret == -1:   return create_error("you must be logged in"), 401
    elif ret == -2: return create_error("internal error"), 500
    return create_result("new task added"), 200

def delete_task(sessionID, taskID):
    task_class = task(sessionID)
    ret = task_class.deleteTask(taskID)
    task_class.conn.close()
    if ret == -1:   return create_error("you must be logged in"), 401
    elif ret == -2: return create_error("internal error"), 500
    elif ret == -3: return create_error("task id does not exist"), 404
    return create_result("task deleted"), 200