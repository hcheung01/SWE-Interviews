#!/usr/bin/python3
"""
export data Python script
"""

if __name__ == "__main__":
    from collections import OrderedDict
    import json
    import requests

    todos = requests.get("https://jsonplaceholder.typicode.com/todos").json()
    users = requests.get("https://jsonplaceholder.typicode.com/users").json()

    the_format = {}
    info = OrderedDict()
    the_list = []

    with open("todo_all_employees.json", "w") as f:
        for user in users:
            for task in todos:
                if user.get('id') == task.get('userId'):
                    info['username'] = user.get('username')
                    info['task'] = task.get('title')
                    info['completed'] = task.get('completed')
                    the_list.append(info)
                info = OrderedDict()
            the_format[user.get('id')] = the_list
            the_list = []
        json.dump(the_format, f)
