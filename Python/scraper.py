import requests, time
from collections import deque
from bs4 import BeautifulSoup

def isValidLink(link):
    if 'class' not in link.attrs.keys() and link.attrs['href'][:5] == "/wiki" and len(link.contents) == 1 and link.attrs['href'][6:].find('/') == -1 and link.attrs['href'].find(':') == -1:
        return True
    return False

def printPages(start_page, n):
    linkQueue = deque()
    max = n
    index = 0
    prefix = "https://en.wikipedia.org"
    url=prefix + start_page
    
    linkQueue.append(url)

    start = time.time()
    with open('compare.csv', 'a',encoding='utf-8') as file:
        while len(linkQueue) != 0:
            currURL = linkQueue.popleft()

            response = requests.get(currURL)
            time.sleep(0.1)
            
            soup = BeautifulSoup(response.content, 'html.parser')

            file.write(soup.find(id='firstHeading').text + '\n')

            allLinks = soup.find(id="bodyContent").find_all("p")

            for p in allLinks:
                for link in p.findAll("a"):
                    if isValidLink(link):
                        linkQueue.append(prefix + link.attrs['href'])
                        file.write(link.attrs['href'][6:] + ',')
                        index += 1

                    if index > max:
                        break

                if index > max:
                    break
            
            if index > max:
                break
            
            file.write('\n\n')

    end = time.time()

    print("Time consumed in working:", end - start)
    print("Queue Size:",len(linkQueue))