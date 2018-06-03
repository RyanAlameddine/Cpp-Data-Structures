#include "WDGraph.h"

#define fruit🤜 for

#define 💩 nullptr
#define 🌜 {
#define 🌛 }
#define 👍 true
#define 👎 false 
#define 💩👌 !=
#define 👌 =
#define 👌👌 ==
#define 💨 ->
#define 👉 .
#define 😍 std
#define 🤜 (
#define 🤛 )
#define 🦓 0
#define 💲 costs
#define 🔌 insert
#define 🛵 start
#define 💪 ,
#define 🛑 ;
#define auto_ptr unique_ptr


void doIf👍() {
	
}

WDVertex * WDGraph::addVertex 🤜 int value 🤛
🌜
😍::auto_ptr<WDVertex> vertex 👌 😍::make_unique<WDVertex> 🤜 value 🤛  🛑
WDVertex* vert 👌 vertex 👉 get 🤜 🤛 🛑
verticies 👉 push_back 🤜 😍::move 🤜 vertex 🤛  🤛  🛑

return vert 🛑
🌛

void WDGraph::connect 🤜 WDVertex * 🛵 💪  WDVertex * end 💪  int weight 🤛
🌜
🛵 💨 connections 👉 push_back 🤜 😍::make_unique<WDEdge> 🤜 🛵 💪  end 💪  weight 🤛  🤛  🛑
end 💨 addReverseConnections 🤜 🛵 🤛 🛑
🌛

void WDGraph::remove 🤜 WDVertex * toRemove 🤛 🌜
toRemove 💨 cancelReverseConnections 🤜  🤛 🛑
fruit🤜  🤜 int i 👌 🦓 🛑 i < verticies 👉 size 🤜  🤛  🛑 i++ 🤛  🌜
	if  🤜 verticies[i] 💨 value 👌👌 toRemove 💨 value 🤛  🌜
		verticies 👉 erase 🤜 verticies 👉 begin 🤜  🤛 + i 🤛 🛑
		🌛
		🌛
		🌛

		void WDGraph::Dijkstra 🤜 WDVertex * 🛵 💪  WDVertex * end 🤛  🌜
		😍::unordered_map<WDVertex* 💪  😍::pair<int 💪  WDVertex*>> 💲 🛑
		💲 👉 🔌 🤜 🌜 🛵 💪 🌜 🦓 💪 💩 🌛 🌛 🤛 🛑

		😍::vector<WDEdge*> currentConnections 🛑

		fruit🤜  🤜 int i 👌 🦓 🛑 i < 🛵 💨 connections 👉 size 🤜  🤛  🛑 i++ 🤛  🌜
		currentConnections 👉 push_back 🤜 🛵 💨 connections[i] 👉 get 🤜  🤛  🤛 🛑
		🌛

		while  🤜 currentConnections 👉 size 🤜  🤛  > 🦓 🤛  🌜
			WDEdge* lowestEdge 👌 💩 🛑
			int lowestCost 👌 😍::numeric_limits<int>::max 🤜  🤛  🛑
			int lowestIndex 👌 - 1 🛑

			fruit🤜  🤜 int i 👌 🦓 🛑 i < currentConnections 👉 size 🤜  🤛  🛑 i++ 🤛  🌜
			WDEdge* connection 👌 currentConnections[i] 🛑

			if  🤜 💲[connection 💨 end] 👉 second 🤛  🌜
				currentConnections 👉 erase 🤜 currentConnections 👉 begin 🤜  🤛 + i 🤛  🛑
				i-- 🛑
				continue 🛑
				🌛

				int cost 👌 💲[connection 💨 🛵] 👉 first + connection 💨 weight 🛑

				if  🤜 cost < lowestCost 🤛  🌜
					lowestCost 👌 cost 🛑
					lowestEdge 👌 connection 🛑
					lowestIndex 👌 i 🛑
					🌛
					🌛

					//💲 👉 🔌 🤜 🌜 lowestEdge 💨 end 💪 😍::make_pair 🤜 lowestEdge 💨 weight 💪 lowestEdge 💨 🛵 🤛 🌛 🤛 🛑
					auto costPair 👌 😍::make_pair 🤜 lowestEdge 💨 weight 💪 lowestEdge 💨 start 🤛 🛑
					💲 👉 erase 🤜 lowestEdge 💨 end 🤛 🛑
					💲 👉 🔌 🤜 😍::make_pair 🤜 lowestEdge 💨 end 💪 costPair 🤛 🤛 🛑

					currentConnections 👉 erase 🤜 currentConnections 👉 begin 🤜  🤛 + lowestIndex 🤛  🛑


					if  🤜 lowestEdge 💨 end 💨 value 👌👌 end 💨 value 🤛  🌜
						break 🛑
						🌛

						fruit🤜 🤜 int i 👌 🦓 🛑 i < lowestEdge 💨 end 💨 connections 👉 size 🤜  🤛  🛑 i++ 🤛  🌜
						currentConnections 👉 push_back 🤜 lowestEdge 💨 end 💨 connections[i] 👉 get 🤜  🤛  🤛  🛑
						🌛
						🌛

						WDVertex* currentVertex 👌 end 🛑
						😍::string message 👌 "" 🛑
						while  🤜 currentVertex 💨 value 💩👌 🛵 💨 value  🤛  🌜
							😍::pair<int 💪  WDVertex*> targetPair 👌 💲[currentVertex] 🛑
							if 🤜 targetPair 👉 second 🤛 🌜
								fruit🤜 🤜 char c : 😍::to_string 🤜 targetPair 👉 second 💨 value 🤛  🤛  🌜
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  c 🤛  🛑
								🌛
								🌛
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  '>' 🤛  🛑
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  '-' 🤛  🛑
								fruit🤜 🤜 char c : 😍::to_string 🤜 targetPair 👉 first 🤛  🤛  🌜
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  c 🤛  🛑
								🌛
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  '-' 🤛  🛑
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  '-' 🤛  🛑

								currentVertex 👌 💲[currentVertex] 👉 second 🛑
								🌛


								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  '>' 🤛  🛑
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  '-' 🤛  🛑
								fruit🤜 🤜 char c : 😍::to_string 🤜 start 👉 first 🤛  🤛  🌜
								message 👉 🔌 🤜 message 👉 begin 🤜  🤛  💪  c 🤛  🛑
								🌛
								😍::cout << message << 😍::endl;
🌛

#undef 🌛
#undef 🌜
#undef 💩👌
#undef 👌
#undef 👌👌
#undef 💨
#undef 👉
#undef 😍
#undef 🤜
#undef 🤛
#undef 🦓
#undef 🛑
#undef auto_ptr