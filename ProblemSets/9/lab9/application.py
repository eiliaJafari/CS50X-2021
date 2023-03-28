import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database

        message = ""
        name = request.form.get("name")
        year = request.form.get("year")
        month = request.form.get("month")
        day = request.form.get("day")
        if not name:
            message = "Name not found"
        elif not year:
            message = "year not found"
        elif not month:
            message = "month not found"
        elif not day:
            message = "day not found"
        else:

            # TODO: Display the entries in the database on index.html

            db.execute(
                "INSERT INTO birthdays (name, year, month, day) VALUES(?, ?, ?, ?)",
                name,
                year,
                month,
                day,
            )
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", message=message, birthdays=birthdays)
    else:
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)

@app.route("/delete", methods=["POST"])
def delete():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")