import pymysql as sql
from hashlib import sha512
from json import dumps
from app import app

def initiate_connection():
    return (sql.connect(host=app.config['DATABASE_HOST'] or app.config['DATABASE_SOCK'],
                        user=app.config['DATABASE_USER'],
                        password=app.config['DATABASE_PASS'],
                        db=app.config['DATABASE_NAME']))

class task():

    def __init__(self, sessionID):
        self.conn = initiate_connection()
        self.sessionID = sessionID

    def getAllTasks(self):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1, None
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `user_id` FROM `user` WHERE `sessionID`=%s", (self.sessionID,))
                user_id = str(cursor.fetchone()[0])
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `fk_task_id` FROM `user_has_task` WHERE `fk_user_id`=%s", (user_id,))
                task_ids = cursor.fetchall()
                if (len(task_ids) == 0): return 0, []
                task_ids = ','.join(list(map(lambda x: str(x[0]), task_ids)))
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT * FROM `task` WHERE `task_id` IN ({})".format(task_ids))
                tasks = cursor.fetchall()
                tasks = list(map(list, tasks))
            return 0, tasks
        except:
            return -2, None

    def getTaskById(self, taskID):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1, None
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `user_id` FROM `user` WHERE `sessionID`=%s", (self.sessionID,))
                user_id = str(cursor.fetchone()[0])
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user_has_task` WHERE `fk_user_id`=%s AND `fk_task_id`)", (user_id, taskID))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -3, None
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT * FROM `task` WHERE `task_id`=%s", (taskID,))
                tasks = cursor.fetchone()[0]
            return 0, tasks
        except:
            return -2, None

    def updateTaskById(self, taskID, taskObj):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `user_id` FROM `user` WHERE `sessionID`=%s", (self.sessionID,))
                user_id = str(cursor.fetchone()[0])
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user_has_task` WHERE `fk_user_id`=%s AND `fk_task_id`=%s)", (user_id, taskID))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -3
            with self.conn.cursor() as cursor:
                cursor.execute("UPDATE `task` SET `title`=%s, `begin`=%s, `end`=%s, `status`=%s WHERE `taskID`=%s",
                (taskObj['title'], taskObj['begin'], taskObj['end'], taskObj['status'], taskID))
            self.conn.commit()
            return 0
        except:
            return -2

    def createTask(self, taskObj):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `user_id` FROM `user` WHERE `sessionID`=%s", (self.sessionID,))
                user_id = str(cursor.fetchone()[0])
            with self.conn.cursor() as cursor:
                cursor.execute("INSERT INTO `task` (`title`, `begin`, `end`, `status`) VALUES (%s, %s, %s, %s)",
                (taskObj['title'], taskObj['begin'], taskObj['end'], taskObj['status']))
            self.conn.commit()
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT LAST_INSERT_ID()")
                task_id = str(cursor.fetchone()[0])
            with self.conn.cursor() as cursor:
                cursor.execute("INSERT INTO user_has_task (fk_user_id, fk_task_id) VALUES (%s, %s)", (user_id, task_id))
            self.conn.commit()
            return 0
        except:
            return -2

    def deleteTask(self, taskID):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `user_id` FROM `user` WHERE `sessionID`=%s", (self.sessionID,))
                user_id = str(cursor.fetchone()[0])
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user_has_task` WHERE `fk_user_id`=%s AND `fk_task_id`=%s)", (user_id, taskID))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -3
            with self.conn.cursor() as cursor:
                cursor.execute("DELETE FROM `task` WHERE `task_id`=%s", (taskID,))
            self.conn.commit()
            return 0
        except:
            return -2

class user():

    def __init__(self, username, password, sessionID):
        self.conn = initiate_connection()
        self.username = username
        self.password = sha512(password.encode('utf-8')).hexdigest()
        self.sessionID = sessionID

    def getUserInfo(self):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1, None
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT `data` FROM `user` WHERE `sessionID`=%s", (self.sessionID,))
                keys = cursor.fetchone()[0]
            return 0, keys
        except:
            return -2, None

    def signoutUser(self):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if (ret == 0): return -1
            with self.conn.cursor() as cursor:
                cursor.execute("UPDATE `user` SET `sessionID`=NULL WHERE `sessionID`=%s", (self.sessionID,))
            self.conn.commit()
            return 0
        except:
            return -2

    def registerUser(self, keys: dict):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `username`=%s)", (self.username,))
                ret = int(cursor.fetchone()[0])
                if ret == 1: return -1
            with self.conn.cursor() as cursor:
                cursor.execute("INSERT INTO `user` (`username`, `password`, `data`) VALUES (%s, %s, %s)", (self.username, self.password, dumps(keys)))
            self.conn.commit()
            return 0
        except:
            return -2

    def submitSessionID(self):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `sessionID`=%s)", (self.sessionID,))
                ret = int(cursor.fetchone()[0])
                if ret == 1: return -1
            with self.conn.cursor() as cursor:
                cursor.execute("UPDATE `user` SET `sessionID`=%s WHERE `username`=%s", (self.sessionID, self.username))
            self.conn.commit()
            return 0
        except:
            return -2

    def checkInvalidCredentials(self):
        try:
            with self.conn.cursor() as cursor:
                cursor.execute("SELECT EXISTS(SELECT * FROM `user` WHERE `username`=%s AND `password`=%s)", (self.username, self.password))
                ret = int(cursor.fetchone()[0])
                if ret == 1: return 0
                else: return -1
        except:
            return -2
