
template<typename TValue>
void UUVertex<TValue>::Connect(UUVertex<TValue>* target)
{
	this->connections.push_back(target);
	target.connections.push_back(this);
}