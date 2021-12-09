import argparse, scraper

def startPageURL(title):
    title = "/wiki/" + title.replace(" ", "_")
    return title

# CLI Arguments
parser = argparse.ArgumentParser(description='Wiki Game Solver')
parser.add_argument("-s", "--start", help="Title of Start Page.")
parser.add_argument("-d", "--destination", help="Title of Target Page.")
parser.add_argument("-n", "--number", type=int, help="Number of Links.")

args = parser.parse_args()
start_page = args.start
dest_page = args.destination
max = args.number

# GET Start Page
scraper.printPages(startPageURL(start_page), max)
