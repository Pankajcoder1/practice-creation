from bs4 import BeautifulSoup
import requests

# class detailsSraper():
# 	def __init__(self):
# 		self.link=""
# 		# this will take link

# 	def find_details(self,link):
# 		try:

def find_details(link):
	# print("/UP")
	current_rank=""
	user_id=""
	current_rating=""
	highest_rank=""
	highest_rating=""
	# country=""
	email=""



	page_url=requests.get(link)
	if(page_url.status_code!=200):
		print(f"Account access request failed ....:{page_url.status_code}")
	else:
		soup=BeautifulSoup(page_url.content,"html.parser")
		# rank get here.
		current_rank=soup.find("div",class_="user-rank").find("span")
		current_rank=str(current_rank.contents[0])
		# user-id
		user_id=soup.find("h1").find("a",class_="rated-user")
		user_id=str(user_id.contents[0])
		# highest rank
		highest_rank=soup.find("span",class_="smaller").find("span")
		highest_rank=str(highest_rank.contents[0])
		highest_rank=highest_rank.split(',')[0]
		# # highest rating
		highest_rating=soup.find("span",class_="smaller").findChildren()[1].contents[0]
		highest_rating=int(highest_rating)
		#current rating
		current_rating=soup.find("div",class_="info").find("ul").findChildren()[2].contents
		current_rating=int(current_rating[0])
		# country
		# country=soup.find("div",class_="main-info").findChildren()[4].contents

		#email
		# email=soup.find("div",class_="info").find("ul").findChildren()[11].contents[2]
		# email=str(email).split('\n')[3].split(' ')[24]
		# email=str(email)
		# 13 pe online milega
		print("hai ",email)


		# print("all details here ... ")
		print("current rank is ",current_rank)
		print("user_id is ",user_id)
		print("current_rating is ",current_rating)
		print("highest_rank is ",highest_rank)
		print("highest_rating is ",highest_rating)
		# print("country is ",country)











# print("Enter link first : ",end=" ")
# link=input()
# link="https://codeforces.com/profile/Pankaj_Kumar1"
# link="https://codeforces.com/profile/tourist"
link=input("Enter link first ")
find_details(link)